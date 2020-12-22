// assignment 5-2
/*
将图的邻接表转换为邻接矩阵
算法思想：
	遍历图的所有边，得到边的两端点，输入邻接矩阵
*/
const int maxn = 110;
int n, e, G[maxn][maxn];
vector<int> adj[maxn];

int main() {
	// 初始化
	//fill(G[0], G[0] + maxn * maxn, 0);

	scanf("%d%d", &n, &e);
	int a, b;
	for (int i = 0; i < e; i++)
	{
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}

	// 将邻接表转换为邻接矩阵
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
		{
			b = adj[i][j];
			G[i][b] = 1;
		}
	}

	return 0;
}