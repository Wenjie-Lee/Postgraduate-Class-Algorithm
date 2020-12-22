#include <stdio.h>
#define MAX 100
#define max(x,y) ((x)>(y)?(x):(y))
//问题表示
int a[]={68,69,54,64,68,64,70,67,78,62,98,87};
int n=sizeof(a)/sizeof(a[0]);
//求解结果表示
int ans=0;
int dp[MAX];
void solve(int a[],int n)		//求dp
{	int i,j;
	for(i=0;i<n;i++)
	{	dp[i]=1;
		for(j=0;j<i;j++)
			if (a[i]<a[j])	//由求最长递增子序列长度的a[i]>a[j]改为a[i]<a[j]
				dp[i]=max(dp[i],dp[j]+1);
	}
	ans=dp[0];
	for(i=1;i<n;i++)			//求出第一个最大的dp[i]
		ans=max(ans,dp[i]);
}
void main()
{
	solve(a,n);
	printf("%d\n",ans);		//输出4
}
