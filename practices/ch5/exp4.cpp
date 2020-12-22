#include <stdio.h>
//问题表示
int x[5];					//存放问题解
int n=5;
void swap(int &a, int &b)	//交换两个元素
{
	int tmp=a;
	a=b; b=tmp;
}
void dispasolution(int x[])		//输出一个解
{
	printf("  %d*%d-%d*%d-%d=1\n",x[0],x[1],x[2],x[3],x[4]);
}
void dfs(int i)		//求解算法
{
	if (i==n)		//达到叶子结点
	{
		if (x[0]*x[1]-x[2]*x[3]-x[4]==1)
			dispasolution(x);
		
	}
	else
	{
		for (int j=i;j<n;j++)
		{
			swap(x[i],x[j]);
			dfs(i+1);
			swap(x[i],x[j]);
		}
	}
}
void main()
{
	for (int j=0;j<n;j++)
		x[j]=j+1;
	printf("求解结果\n");
	dfs(0);
}
