#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXQ 101
#define MAXN 10
#define MAXM 10
int H[4] = {0, 1, 0, -1};					//水平偏移量,下标对应方位号0～3
int V[4] = {-1, 0, 1, 0};					//垂直偏移量
struct Position								//坐标类型
{	int x,y;
	Position() {}
	Position(int i,int j)						//构造函数
	{	x=i;
		y=j;
	}
};
//问题表示
int n=7;
int m=7;
int grid[MAXN][MAXM]={
	{0,0,1,1,0,0,0},
	{0,0,0,1,0,0,0},
	{0,0,0,0,1,0,0},
	{0,0,0,1,1,0,0},
	{1,0,0,0,1,0,0},
	{1,1,1,0,0,0,0},
	{1,1,1,0,0,0,0} };
Position a(2,1),b(3,5);						//起始位置a和目标位置b
//求解结果表示
int bestlen=INF;								//最优路径的路径长度
vector<Position> bestpath;						//最优路径
int Count=0;								//搜索空间中结点数累计,全局变量
//---------------自己设计非环形队列--------------
typedef struct 
{	int no;								//结点在队列数组中的下标
	Position p;								//当前结点行、列号
	int length;								//当前结点的路径长度
	int pre;								//当前结点的的前驱结点在队列中的下标
} NodeType;
class QUEUE								//声明非环形队列类
{
private:
	NodeType data[MAXQ];
	int front,rear;							//队头队尾指针
public:
	QUEUE()								//构造函数
	{
		front=rear=-1;
	}	
	bool empty()							//队列算法为空
	{
		return front==rear;
	}
	void push(NodeType e)					//结点e进队
	{	rear++;
		data[rear]=e;
	}
	NodeType pop()							//出队结点e
	{	front++;
		return data[front];
	}
	void GetPath(int s,vector<Position> &path)		//从s构造一条逆路径path
	{	int k=s;
		while (k!=-1)						//根结点的pre为-1
		{	path.push_back(data[k].p);
			k=data[k].pre;					//反向推导路径
		}
	}
};
//----------------------------------------------------------
void solve()								//求布线问题的最优解
{	NodeType e,e1;						//定义2个结点
	Position p,p1;
	QUEUE qu;							//定义一个队列qu
	e.no=Count++;							//设置结点位置
	e.pre=-1;
	e.p=a;								//起始点
	e.length=0;
	qu.push(e);								//根结点进队
	while (!qu.empty())						//队不空循环
	{	e=qu.pop();						//出队结点e作为当前结点
		p=e.p;
		if (p.x==b.x && p.y==b.y)				//e是一个叶结点
		{	if (e.length<bestlen)				//比较找最优解
			{	bestlen=e.length;				//保存最短路径长度
				bestpath.clear();
				qu.GetPath(e.no,bestpath);		//保存最短路径
			}
		}
		else								//e不是叶结点
		{	for (int j=0; j<4; j++)				//检查e的周围4个结点
			{	p1.x=p.x+H[j];				//求出p的一个相邻结点p1
				p1.y=p.y+V[j];
				if (p1.x>=0 && p1.x<n && p1.y>=0 && p1.y<m && grid[p1.x][p1.y]==0)
				{	//p1必须是可以走的结点
					if (e.length+1<bestlen)	 	//剪枝
					{	e1.no=Count++;		//设置结点编号
						e1.length=e.length+1;	//路径长度增1
						e1.pre=e.no;
						e1.p=p1;
						qu.push(e1);		//孩子结点进队
						grid[p1.x][p1.y]=-1;	//避免来回搜索
					}
				}
			}
		}
	}
}
int main()
{	solve();
	printf("最佳方案:\n");
	printf("  路径长度=%d\n", bestlen);
	vector<Position>::reverse_iterator it;
	printf("  路径: ");
	for (it=bestpath.rbegin();it!=bestpath.rend();++it)
		printf("[%d,%d] ",it->x,it->y);
	printf("\n");
	return 0;
}
