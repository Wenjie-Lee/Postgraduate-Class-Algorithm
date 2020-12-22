#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
//问题表示
int n=4;							//皇后个数
//求解结果表示
int Count=1;						//累计队列中的结点个数,全局变量
struct NodeType						//声明队列中的结点类型
{
	int no;							//结点编号
	int row;						//当前考察的行号
	vector<int> cols;				//存放已经放置皇后的列号
	bool operator<(const NodeType &s) const	//重载>关系函数
	{	return row<s.row;  }		//row越大越优先

};
void dispnode(NodeType e)			//输出一个结点内容
{
	if (e.row!=-1)
		printf("编号:%d, 对应位置(%d,%d)\n",e.no,e.row,e.cols[e.row]);
	else
		printf("编号:%d, 对应位置(%d,*)\n",e.no,e.row);
}
bool Valid(vector<int> cols,int i,int j)  	//测试(i,j)位置能否摆放皇后
{	int k=0;
	while (k<i)       				//k=0～i-1是已放置了皇后
	{	if ((cols[k]==j) || (abs(cols[k]-j)==abs(k-i)))
		    return false;				//有冲突时返回假
	    k++;
	}
	return true;						//没有冲突时返回真
}
void solve()						//求皇后问题解
{	int i,j;
	NodeType e,e1;					//定义2个结点
	priority_queue<NodeType> qu;				//定义一个队列qu
	e.no=Count++;					//建立根结点
	e.row=-1;						//行号初始化为-1
	qu.push(e);						//根结点进队
	printf("  进队: "); dispnode(e);
	while (!qu.empty())				//队不空循环
	{
		e=qu.top(); qu.pop();		//出队结点e作为当前结点
		printf("  出队: "); dispnode(e);
		if (e.row==n-1)				//达到叶结点
		{
			printf("  产生一个解: ");
			for (i=0;i<n;i++)			//行、列号从1开始
				printf("[%d,%d] ",i+1,e.cols[i]+1);
			printf("\n");
			return;
		}
		else						//e不是叶结点
		{	for (j=0; j<n; j++)		//检查所有列号
			{	i=e.row+1;			//考察第i个皇后
				if (Valid(e.cols,i,j))	//扩展与e结点中所有皇后没有冲突的子结点
				{
					e1.no=Count++;
					e1.row=i;
					e1.cols=e.cols;
					e1.cols.push_back(j);
					qu.push(e1);
					printf("     进队子结点: "); dispnode(e1);
				}
			}
		}
	}
}
int main()
{	printf("%d皇后问题求解过程:\n",n);
	solve();
	return 0;
}
