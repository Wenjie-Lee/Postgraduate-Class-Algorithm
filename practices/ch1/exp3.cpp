#include <stdio.h>
#include <queue>
using namespace std;
int solve(queue<int> &qu,int k)	//出队第k个元素
{	queue<int> tmpqu;
	int e;
	for (int i=0;i<k-1;i++)		//出队qu的k-1个元素并进tmpqu队
	{	tmpqu.push(qu.front());
		qu.pop();
	}
	e=qu.front();				//出队qu的第k个元素
	qu.pop();
	while (!qu.empty())		//将qu的剩余元素出队并进队tmpqu
	{	tmpqu.push(qu.front());
		qu.pop();
	}
	qu=tmpqu;					//将tmpqu复制给qu
	return e;
}
void disp(queue<int> &qu)		//出队qu的所有元素
{	while (!qu.empty())
	{	printf("%d ",qu.front());
		qu.pop();
	}
	printf("\n");
}
void main()
{
	printf("实验结果\n");
	queue<int> qu;
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	printf("  元素1,2,3,4依次进队qu\n");
	int k=3;
	int e=solve(qu,k);
	printf("  出队第%d个元素是: %d\n",k,e);
	printf("  qu中其余元素出队顺序: ");
	disp(qu);
}
