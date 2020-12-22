// practice 9-3
/*
求解最大流最小费用问题

源点：有n个点，有m条有向边，其中有一个点比较特殊，它只出不进，即入度为0。这样的点我们称为源点，一般用字母S表示。
汇点：另一个点也比较特殊，只进不出，即出度为0。这样的点我们称为汇点，一般用字母T表示。
容量和流量：每条有向边上有两个量，容量和流量，从i到j的容量表示为c[i,j]表示，流量则用f[i,j]表示。

最大流：把源点比作工厂的话，问题就是求工厂最大可以发出多少货物，而不至于超过道路的容量限制，也即，最大流问题。

有第一、第二尺度，且非负，可以用dijkstra、SPFA算法求解
*/

// 解法1：SPFA算法

const int maxn = 110, maxe = 10010, inf = 99999999;
struct edge {
	edge *op;
	int u, v, capacity, flow, cost;
	edge(int _u, int _v, int _c, int _f, int _cost) :
		u(_u), v(_v), capacity(_c), flow(_f), cost(_cost) {}
} es[maxe], *V[maxe];
int n, m, s, t, num_edge = 0;
vector<edge> e;
vector<int> adj[maxn];
// 流量，		路径，	边入队的个数，	反向边记录
int flow[maxn], d[maxn], num[maxn], pre[maxn];
int maxflow = 0, mincost = inf;
bool inq[maxn];

void add_edge(int u, int v, int cap, int cost) {
	e.push_back(edge(u, v, cap, 0, cost));
	e.push_back(edge(u, v, cap, 0, -cost));
	adj[u].push_back(num_edge++);
	adj[v].push_back(num_edge++);
}

bool SPFA(int s, int t) {
	// init
	queue<int> q;
	memset(num, 0, sizeof(num));
	memset(inq, false, sizeof(inq));
	memset(pre, -1, sizeof(pre));
	fill(d, d + maxn, inf);
	d[s] = 0; 
	num[s] = 1;
	q.push(s);

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i = 0; i < adj[u].size(); i++)
		{
			edge ev = e[adj[u][i]];
			int v = ev.v;
			if (ev.capacity > ev.flow && d[v] > d[u] + ev.cost)
				// capacity > flow 此边还未满;
				// d[v] > d[u] + ev.cost 松弛
			{
				d[v] = d[u] + ev.cost;	
				pre[v] = adj[u][i];		// 记录点v的反向边idx
				flow[v] = min(flow[u], ev.capacity - ev.flow);	// 从u到达v的流量
				if (!inq[v])
				{
					q.push(v);
					num[v]++;
					if (num[v] == n)
						return false;	// 有负环
				}
			}
		}
	}

	return pre[t] != -1;	// 是否找到增广路径
}

void MincostMaxflow() {
	while (SPFA(s, t)) {
		maxflow += flow[t];
		mincost += d[t] * flow[t];
		// 正向边、反向边流量的修改
		for (int u = t; u != s; u = e[pre[u]].u)
		{
			e[pre[u]].flow += flow[t];
			e[pre[u] ^ 1].flow -= flow[t];
		}
	}
}

int main() {
	// init
	fill(d, d + maxn, inf);
	

	cin >> n >> m >> s >> t;
	int u, v, cap, cost;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> cap >> cost;
		// 单向图
		add_edge(u, v, cap, cost);
	}
	MincostMaxflow();
	cout << mincost << " " << maxflow;
	return 0;
}

// 解法2：加入势函数的Djikstra算法
#define P pair<int, int>
const int maxn = 110, maxe = 10010, inf = 9999999;
int n, m, s, t, mincost = inf, maxflow = 0;
struct edge {
	int v, cap, flow, cost, rev;	// rev存放反向边在G的idx
	edge(int _v, int _c, int _f, int _cost, int _rev) :
		v(_v), cap(_c), flow(_f), cost(_cost), rev(_rev) {}
};
vector<edge> G[maxn];
int h[maxn], d[maxn], prevu[maxn], prevv[maxn];	// 记录反向边

void add_edge(int u, int v, int cap, int cost) {
	G[u].push_back(edge(v, cap, 0, cost, G[v].size()));
	G[v].push_back(edge(u, 0, 0, -cost, G[u].size() - 1));	// 记得-1，上一行刚+1
}

void MCMF(int s, int t, int f) {
	fill(h, h + n, 0);

	while (f > 0)
	{
		priority_queue<P, vector<P>, greater<P> > q;
		fill(d, d + maxn, inf);
		d[s] = 0;
		q.push(P(0, s));

		while (!q.empty())
		{
			P now = q.top();
			q.pop();
			if (d[now.second] < now.first) continue;
			int v = now.second;
			for (int i = 0; i < G[v].size(); i++)
			{
				edge& e = G[v][i];
				if (e.cap > 0 && d[e.v] > d[v] + e.cost + h[v] - h[e.v])
				{
					d[e.v] = d[v] + e.cost + h[v] - h[e.v];
					prevv[e.v] = v;	// prevv记录边的终点
					prevu[e.v] = i;	// prevu记录边的起点
					q.push(P(d[e.v], e.v));
				}
			}
			if (d[t] == inf) break;
			for (int i = 0; i < n; i++)
				h[i] += d[i];
			int d = f;
			for (int v = 0; v != s; v = prevv[v])
				d = min(d, G[prevv[v]][prevu[v]].cap);
			f -= d;
			maxflow += d;
			mincost += d * h[t];
			for (int v = 0; v != s; v = prevv[v])
			{
				edge& e = G[prevv[v]][prevv[v]];
				e.cap -= d;
				G[v][e.rev].cap += d;
			}
		}
	}
}

int main() {
	cin >> n >> m >> s >> t;
	int u, v, cap, cost;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> cap >> cost;
		add_edge(u, v, cap, cost);
	}
	MCMF(s, t, inf);
	cout << "最大流为：" << maxflow << endl;
	cout << "最小费用为" << mincost << endl;
	cout << endl;
	return 0;
}