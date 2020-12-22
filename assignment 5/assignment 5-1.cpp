// assignment 5-1
/*
根据图G的邻接表生成反向邻接表。
算法思想：开辟一个新的邻接表。遍历图G的邻接表，
将所有边的起点作为终点，终点作为起点，记录到新邻接表。

*1
5 5
1 2
1 3
1 4
2 5
3 5
:
adj 1:
adj 2: 1
adj 3: 1
adj 4: 1
adj 5: 2 3
*/
const int maxn = 100;
int n, e;
vector<int> adj[maxn], rev[maxn];
int main() {
	scanf("%d%d", &n, &e);
	int a, b;
	for (int i = 1; i <= e; i++)
	{
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
	}

	// 根据邻接表生成反向邻接表
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < adj[i].size(); j++)
			rev[adj[i][j]].push_back(i);

	for (int i = 1; i <= n; i++)
	{
		printf("adj %d:", i);
		for (int j = 0; j < rev[i].size(); j++)
			printf(" %d", rev[i][j]);
		printf("\n");
	}
	return 0;
}