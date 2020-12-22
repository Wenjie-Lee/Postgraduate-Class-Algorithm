// practice 9-1
/*
DAG求最长路径
解法1：动态规划
	算法思想：
		边界：dp[t] = 0;
		状态转移函数：dp[i] = max{dp[j] + length[i->j]}

解法2： Bellman-Ford算法\SPFA算法
	算法思想：Bellman-Ford算法或SPFA算法是求解单源最短路径的算法，但是他接受负值。
		将图的边权取负值后，最长的边就变成了权值最小的边，可通过求最短路径来求出最长路径。

*1
6 6
0 1 1
0 2 3
1 3 1
2 4 3
3 5 9
4 5 2
0 5
:（解法1）11(0->1->3->5)
:（解法2）11(0->1->3->5)
*/

// 解法1：动态规划
const int maxn = 110, inf = 99999999;
int n, m, s, t, G[maxn][maxn], d[maxn];
int dp[maxn];
bool vis[maxn];

int DP(int i) {
	if (vis[i]) return dp[i];
	
	vis[i] = 1;
	for (int j = 0; j < n; j++)
	{
		if (G[i][j] != inf)
			dp[i] = max(dp[i], DP(j) + G[i][j]);
	}
	return dp[i];
}

int main() {
	// Solution 1: dynamic programming
	// init
	fill(G[0], G[0] + maxn * maxn, inf);
	fill(dp, dp + maxn, -1);

	int a, b, l;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &l);
		G[a][b] = l;	// 单向图
	}
	scanf("%d%d", &s, &t);

	// init dp
	dp[t] = 0;
	vis[t] = 1;
	printf("%d", DP(0));

	return 0;
}

// 解法2： SPFA
const int maxn = 110, maxe = 10010, inf = 99999999;
int n, m, s, t, d[maxn], num[maxn];
struct node {
	int v, dis;
	node(int _v, int _dis) : v(_v), dis(_dis) {}
};
vector<node> adj[maxn];
bool inq[maxn];

bool SPFA(int s) {
	memset(num, 0, sizeof(num));
	memset(inq, false, sizeof(inq));
	fill(d, d + maxn, inf);

	queue<int> q;
	q.push(s);
	inq[s] = true;
	num[s]++;
	d[s] = 0;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = false;

		for (int j = 0; j < adj[u].size(); j++)
		{
			int v = adj[u][j].v;
			int dis = adj[u][j].dis;
			if (d[u] + dis < d[v]) {
				d[v] = d[u] + dis;
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
					num[v]++;
					if (num[v] >= n) return false;	// 有可达负环
				}
			}
		}
	}
	return true;
}

int main() {
	// Solution 1: dynamic programming
	// init
	

	int a, b, l;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &l);
		node no = node(b, -l);	// 注意要取反值
		adj[a].push_back(no);	// 单向图
	}
	scanf("%d%d", &s, &t);

	SPFA(s);
	
	printf("%d", -d[t]);	// 反值要变回正数

	return 0;
}