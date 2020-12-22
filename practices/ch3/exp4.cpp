#include <stdio.h>
#define MAXN 201
int fset(int n)			//求set(n)的元素个数
{	int ans=1;
	if(n>1)
		for(int i=1;i<=n/2;i++)
			ans+=fset(i);
	return ans;
}
void main()
{
	int n=6;
	printf("求解结果\n");
	printf("  n=%d时半数集元素个数=%d\n",n,fset(n));
}

