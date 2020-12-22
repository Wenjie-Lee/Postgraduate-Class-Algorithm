#include <stdio.h>
void solve(int n) 
{	int x,y,z;
	int count=0;
	for (z=0;z<=n/5;z++)
		for (y=0;y<=(n-z*5)/2;y++)
			if (5*z+2*y<=n)
			{	x=n-5*z-2*y;
				printf("   兑法%d: ",++count);
				if (z!=0) printf("5分硬币%d个 ",z);
				if (y!=0) printf("2分硬币%d个 ",y);
				if (x!=0) printf("1分硬币%d个",x);
				printf("\n");
			}
	printf("   共有%d种兑法\n",count); 
} 
void main() 
{	int n=10;
	printf("求解结果\n");
	solve(n);
}
