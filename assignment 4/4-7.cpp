#include <stdio.h>
#include <string.h>
#define MAXN 15
#define MAXK 100005
#define MOD 1000000007
//问题表示
int n,k;
//求解结果表示
long dp[MAXN][MAXK];
long solve()					//求解算法
{
	int i,j,q;
	memset(dp,0,sizeof(dp));
	for (j=1;j<=k;j++)
		dp[1][j]=1;
	for(i=2;i<=n;i++)
	{
		int sum=0;					//求所有数列个数
		for(j=1;j<=k;j++)
			sum=(sum+dp[i-1][j]) % MOD;
		for(j=1;j<=k;j++)
		{
			int invalid=0;
			for(q=j*2;q<=k;q+=j)	//减去小易不喜欢的数列个数
				invalid+=dp[i-1][q] % MOD;
			dp[i][j]=(sum-invalid+MOD) % MOD;
		}
	}
	long ans=0;
	for(i=1;i<=k;i++)				//累计所有的dp[n][i]
		ans=(ans+dp[n][i]) % MOD;
	return ans;
}
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		printf("%ld\n",solve());
    }
	return 0;
}

