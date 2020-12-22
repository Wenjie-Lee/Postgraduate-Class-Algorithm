#include<stdio.h>
#define MAXN 102
#define MAXM 102
//问题表示
int n;					//部件数
int m;					//供应商数
int cost;				//限定价格
int w[MAXN][MAXM];		//w[i][j]为第i个零件在第j个供应商的重量
int c[MAXN][MAXM];		//c[i][j]为第i个零件在第j个供应商的价格
//求解结果表示
int bestx[MAXN];
int x[MAXN];
int cw=0,cc=0;
int bestw=999999;
void dfs(int i)					//求解算法
{
    if(i>n)						//搜索到叶子结点
    {
		if (cw<bestw)			//比较产生最优解
		{
			bestw=cw;			//当前最小重量
			for(int j=1;j<=n;j++)
				bestx[j]=x[j];
		}
    }
    else
    {
        for(int j=1;j<=m;j++)		//试探每一个供应商
        {
            if(cc+c[i][j]<=cost && cw+w[i][j]<bestw)	//剪枝
            {
                x[i]=j;					//第i个部件选择第j个供应商
                cc+=c[i][j];
                cw+=w[i][j];
                dfs(i+1);
                cc-=c[i][j];			//cc回溯
                cw-=w[i][j];			//cw回溯
            }
        }
    }
}
int main()
{
    int i,j;
	scanf("%d%d%d",&n,&m,&cost);	//输入部件数,供应商数,限定价格
    for(i=1; i<=n; i++)				//输入各部件的在不同供应商的重量
        for(j=1; j<=m; j++)
            scanf("%d",&w[i][j]);
    for(i=1; i<=n; i++)				//输入各部件的在不同供应商的价格
        for(j=1; j<=m; j++)
            scanf("%d",&c[i][j]);
    dfs(1);							//i从1开始搜索
    for(i=1;i<=n;i++)				//输出每个部件的供应商
        printf("%d ",bestx[i]);
	printf("\n%d\n",bestw);			//输出最小重量
    return 0;
}
