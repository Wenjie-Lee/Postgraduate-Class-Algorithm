// assignment 5-3
/*
无向连通图，prim或kruskal算法

*1
5 5
1 2 1
1 3 3
1 4 2
2 5 3
3 5 4
:prim: 9
kruskal: 9
*/
const int maxn = 110, maxe = 10010, inf = 999999999;
// prim
int n, e, G[maxn][maxn], d[maxn];
bool vis[maxn];
struct edge {
	int u, v, cost;
} E[maxe];
// kruskal
int father[maxn];
// prim

int prim() {
	// init
	memset(vis, 0, sizeof(vis));
	fill(d, d + maxn, inf);

	d[1] = 0;
	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		// 找到当前能到达距离最短点
		int u = 0, mind = inf;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && d[j] < mind)
			{
				u = j;
				mind = d[j];
			}
		}
		if (u == 0) return -1;
		vis[u] = 1;
		ans += d[u];
		for (int j = 1; j <= n; j++)
		{
			// j点未访问，u能到达j且以u为中介点可以使j离集合S更近
			if (!vis[j] && G[u][j] != inf && G[u][j] < d[j])
				d[j] = G[u][j];
		}
	}
	return ans;
}

// kruskal
bool cmp(edge a, edge b) {
	return a.cost < b.cost;
}

int findFather(int x) {
	int a = x;
	while (x != father[x])
		x = father[x];
	while (a != father[a])
	{
		int t = a;
		a = father[a];
		father[t] = x;
	}
	return x;
}

int kruskal() {
	int ans = 0, cur_edges = 0;
	for (int i = 0; i < n; i++)
		father[i] = i;
	sort(E, E + e, cmp);
	for (int i = 0; i < e; i++)
	{
		int faU = findFather(E[i].u);
		int faV = findFather(E[i].v);
		if (faU != faV)
		{
			father[faU] = faV;
			ans += E[i].cost;
			cur_edges++;
			if (cur_edges == n - 1) break;
		}
	}
	if (cur_edges != n - 1) return -1;
	return ans;
}

int main() {
	// init
	fill(G[0], G[0] + maxn * maxn, inf);

	scanf("%d%d", &n, &e);
	int a, b, c;
	for (int i = 0; i < e; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		G[a][b] = G[b][a] = c;
		E[i].u = a, E[i].v = b, E[i].cost = c;
	}

	// prim
	printf("prim: %d\n", prim());
	// kruskal
	printf("kruskal: %d\n", kruskal());
	return 0;
}