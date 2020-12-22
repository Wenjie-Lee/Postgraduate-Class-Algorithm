#include<stdio.h>
#include<string.h>
#include <queue>
using namespace std;
#define MAXV 200001
//问题表示
int A[MAXV][MAXV];		//图的邻接矩阵
int n,m,k;
int sno,eno;
int visited[MAXV];
struct NodeType
{
	int vno;			//顶点编号
	int length;			//路径长度
};
int bfs(int sno,int eno)		//广度优先搜索算法
{
	if (sno==eno) return 0;
	NodeType e,e1;
	queue<NodeType> qu;				//定义队列
	e.vno=sno;
	e.length=0;
	qu.push(e);						//结点e进队
	visited[e.vno]=1;
	while (!qu.empty())				//队列不空循环
	{
		e=qu.front(); qu.pop();		//出队结点e
		if (e.vno==eno) 
			return e.length-1;
		for (int j=0;j<n;j++)
		{
			if (A[e.vno][j]!=0)			//到顶点j有边
			{
				if (visited[j]==0)
				{
					e1.vno=j;
					e1.length=e.length+1;
					qu.push(e1);
					visited[j]=1;
				}
			}
		}
	}
	return -1;
}
int main()
{
	while (scanf("%d%d",&n,&m)==2)
	{
		int a,b,i;
		memset(A,0,sizeof(A));
		memset(visited,0,sizeof(visited));
		for (i=0;i<m;i++)		//根据输入建立邻接矩阵
		{
			scanf("%d%d",&a,&b);
			A[a][b]=1;			//无向图
			A[b][a]=1;
		}
		scanf("%d",&k);
		for (i=0;i<k;i++)
		{
			scanf("%d %d",&sno,&eno);
			printf("%d\n",bfs(sno,eno));
		}
	}
	return 0;
}
