#include <stdio.h>
//问题表示
int d=7;
int n=4;
int a[]={2,7,3,6};
//问题求解表示
int bestn=0;
void solve()				//求解汽车加油问题
{	int i,sum;
	for(i=0; i<n; i++)
	{	if(a[i]>d)			//只要有一个距离大于d就没有解
		{	printf("没有解\n");
            	return;
        	}
    	}
    	for(i=0,sum=0; i<n; i++)
	{	sum += a[i];		//累计行驶到i号加油站的距离
		if(sum>d)			//不能到i号加油站,则在i-1号加油站加油
		{	printf("    在%d号加油站加油\n",i-1);
			bestn++;
			sum=a[i];		//累计从i-1号加油站到i号加油站的距离
        }
    }
	printf("  总加油次数: %d\n",bestn);
}
int main()
{	printf("求解结果\n");
	solve();
	return 0;
}
