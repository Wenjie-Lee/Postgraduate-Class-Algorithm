#include <stdio.h>
#define min(x,y) ((x)<(y)?(x):(y))
#define INF 0x3f3f3f3f
#define MAXN 205
//问题表示
int n;
int a[MAXN];
//求解结果表示
int dp[MAXN][MAXN];
int sum[MAXN];
int solve()										//求dp
{
    for(int i=0;i<n;i++)
        dp[i][i] = 0;
    for(int length=1;length<n;length++)			//指定(i,j)的长度
        for(int i=0;i<n-length;i++)				//0≤i≤n-length-1
        {
            int j=i+length;
            dp[i][j] = INF;
            int tmp = sum[j]-(i>0 ? sum[i-1]:0);
            for(int k=i;k<j;k++)
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j] + tmp);
        }
    return dp[0][n-1];
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sum[0] = a[0];
        for(i=1;i<n;i++)
            sum[i] = sum[i-1] + a[i];
        printf("%d\n",solve());
    }
    return 0;
}