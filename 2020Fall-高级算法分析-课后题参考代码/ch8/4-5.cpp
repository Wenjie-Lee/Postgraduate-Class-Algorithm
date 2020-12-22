#include <stdio.h>
#define MAXN 1001
#define MAXS 1001
#define max(x,y) ((x)>(y)?(x):(y))
//问题表示
int n, sum;
int a[MAXN];
long dp[MAXN][MAXS];		// 直接记录方案数
long solve()
{
	int i, j;
	//初始化dp,用前i个组成和为0的方案，只有1种，就是什么都不取，和为0；
	for (i = 0; i < n; i++)
		dp[i][0] = 1;
	//用0个元素不能组成1~sum
	for (j = 1; j < sum; j++)
		dp[0][j] = 0;
	for (i = 1; i <= n; i++)
		for (j = 0; j <= sum; j++)
		{
			if (a[i] <= j)
				dp[i][j] = max(dp[i - 1][j - a[i]] + dp[i - 1][j], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	return dp[n][sum];
}
int main()
{
	scanf("%d%d", &n, &sum);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%ld\n", solve());
	return 0;
}
