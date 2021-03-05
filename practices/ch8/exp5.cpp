#include <stdio.h>
#include <string.h>
#define MAXN 45
#define MAXS MAXN*MAXN/2
//问题表示
int n;
int solve()
{
	int i,j;
	int sum=n*(n+1)/2;
	if (sum%2!=0)
		return 0;
	sum=sum/2;
	int dp[MAXN][MAXS];
	memset(dp,0,sizeof(dp));
	for (i=0;i<=n;i++)
		dp[i][0]=1;
	// 遍历集合
	for (i=1;i<=n;i++)
		for (j=1;j<=sum;j++)
			if (i>sum)
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
    return dp[n][sum]/2;
}
int solve1()
{
	int i,j;
	int sum=n*(n+1)/2;
	if (sum%2!=0)
		return 0;
	sum=sum/2;
	int dp[MAXS];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for (i=1;i<=n;i++)
		for (j=sum;j>=i;j--)
			dp[j]+=dp[j-i];
	return dp[sum]/2;
}

int main()
{
	scanf("%d",&n);
	printf("%d\n",solve());
	printf("%d\n",solve1());
	return 0;
}

