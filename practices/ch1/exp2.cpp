#include <stdio.h>
#include <queue>
using namespace std;
int thk(int a[],int n,int k)		//求a中第k小的元素
{	int i,e;
	priority_queue<int,vector<int>,greater<int> > pq;
	for (i=0;i<n;i++)				//所有元素进队
		pq.push(a[i]);
	for (i=0;i<k;i++)
	{	e=pq.top();
		pq.pop();
	}
	return e;
}
void main()
{	int a[]={1,2,4,5,3};
	int n=sizeof(a)/sizeof(a[0]);
	printf("实验结果\n");
	for (int k=1;k<=n;k++)
		printf("  第%d小的元素: %d\n",k,thk(a,n,k));
}
