#include <stdio.h>
#include <string.h>
#define MAXN 51
#define MAXE 301
//问题表示
int n, m;					//n个顶点，m条边
int a[MAXN][MAXN];
//求解结果表示
int x[MAXN];				//当前解  
int cn;					//当前解的顶点数  
int bestn;					//最大团的顶点数  
void dfs(int i)				//求最大团
{
	if (i > n)				//到达叶结点
	{
		if (cn > bestn)
			bestn = cn;
		return;
	}
	bool complete = true;			//检查顶点i与当前团的相连关系
	for (int j = 1; j < i; j++)
		if (x[j] && a[i][j] == 0)
		{
			complete = false;		//顶点i与顶点j不相连
			break;
		}
	if (complete)				//全相连，进入左子树  
	{
		x[i] = 1;				//选中顶点i  
		cn++;
		dfs(i + 1);
		x[i] = 0;				//回溯  
		cn--;
	}
	if (cn + n - i >= bestn)			//剪枝（右子树）
	{
		x[i] = 0;				//不选中顶点i
		dfs(i + 1);
	}
}
int main()
{
	int s, t;
	while (true)
	{
		bestn = 0;
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;
		memset(a, 0, sizeof(a));
		memset(x, 0, sizeof(x));
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &s, &t);
			a[s][t] = 1;
			a[t][s] = 1;
		}
		dfs(1);
		printf("%d\n", bestn);
	}
	return 0;
}
