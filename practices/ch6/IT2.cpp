#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 102
#define MAXM 102
//问题表示
int n;									//部件数
int m;									//供应商数
int cost;								//限定价格
int w[MAXN][MAXM];						//w[i][j]为第i个部件在第j个供应商的重量
int c[MAXN][MAXM];						//c[i][j]为第i个部件在第j个供应商的价格
typedef struct 
{	int no;								//结点编号
	int i;								//当前结点在解空间中的层次
	int w;								//当前结点的总重量
	int c;								//当前结点的总价格
	int x[MAXN];							//当前结点包含的解向量
} NodeType;
struct Cmp								//队列中关系比较函数
{	bool operator()(const NodeType &s,const NodeType &t)
	{	return (s.w>t.w) || (s.w==t.w && s.c>t.c);
		//w越小越优先,当w相同时v越小越优先
	}
};
//求解结果表示
int bestw=INF;							//最优方案的总重量
int bestc=INF;							//最优方案的总价格
int bestx[MAXN];							//最优方案,bestx[i]表示部件i分配的供应商
int Count=1;								//搜索空间中结点数累计,全局变量
void solve()								//求最小重量机器设计的最优解
{	NodeType e,e1;						//定义2个结点
	priority_queue<NodeType,vector<NodeType>,Cmp > qu;	//定义一个优先队列qu
	e.no=Count++;							//设置结点编号
	e.i=0;								//根结点层次计为0,叶结点层次为n
	e.w=0;
	e.c=0;
	memset(e.x,0,sizeof(e.x));			//初始化根结点的解向量
	qu.push(e);							//根结点进队
	while (!qu.empty())					//队不空循环
	{	e=qu.top(); qu.pop();				//出队结点e作为当前结点
		if (e.i==n)						//e是一个叶结点
		{	if (e.c<=cost && e.c<bestc && e.w<bestw)//比较找最优解
			{	//选择总价格<cost,最小重量和最小价格的方案
				bestw=e.w;				//更新bestw
				bestc=e.c;				//更新bestc
				for (int j=1;j<=n;j++)	//复制解向量e.x->bestx
					bestx[j]=e.x[j];
			}
		}
		else								//e不是叶结点
		{	for (int j=1; j<=m; j++)			//每一层检查所有供应商j
			{	if (e.c+c[e.i+1][j]<=cost && e.c+c[e.i+1][j]<bestc 
					&& e.w+w[e.i+1][j]<bestw)
				{	/*剪枝：选择总价格<=cost,总重量小于最小重量
						   和总价格小于最小价格进行扩展*/
					e1.no=Count++;			//设置结点编号
					e1.i=e.i+1;				//建立孩子结点
					e1.w=e.w+w[e1.i][j];		//修改e.w
					e1.c=e.c+c[e1.i][j];		//修改e.c
					for (int k=1; k<=n; k++) 	//复制解向量e.x->e1.x
						e1.x[k]=e.x[k];
					e1.x[e1.i]=j;			//为部件选择选择供应商j
					qu.push(e1);			//孩子结点e1进队
				}
			}
		}
	}
}
int main()
{	int i,j;
	scanf("%d%d%d",&n,&m,&cost);	//输入部件数,供应商数,限定价格
	for(i=1; i<=n; i++)				//输入各部件的在不同供应商的重量
		for(j=1; j<=m; j++)
			scanf("%d",&w[i][j]);
	for(i=1; i<=n; i++)				//输入各部件的在不同供应商的价格
		for(j=1; j<=m; j++)
			scanf("%d",&c[i][j]);
	solve();
	for(i=1;i<=n;i++)				//输出每个部件的供应商
		printf("%d ",bestx[i]);
	printf("\n%d\n",bestw);			//输出最小重量
	return 0;
}
