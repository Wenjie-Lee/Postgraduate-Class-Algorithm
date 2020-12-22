// assignment 4-8

/*
合并石头堆
    dp[i][j] i表示石头堆起始位置，j表示末尾位置
    子问题：dp[i][k], dp[k+1][j]各自的最小代价，分到最小边界是一个石头堆
边界：
    （1） 一个石头堆是没有代价的，dp[i][i]=0, sum[i][i] = num[i];
状态转移：
    （1） i==j时，dp[i][j] = 0;
    （2） i!=j时，dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]) + sum[i][j];
        

*1
3 1 2 3
:9
*2
7 13 7 8 16 21 4 18
:239
*/
const int maxn = 210, maxc = 0x3f3f3f3f;
int n, num[maxn], dp[maxn][maxn], sum[maxn][maxn];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);

    fill(dp[0], dp[0] + maxn*maxn, maxc);

    // boundary init
    for (int i = 1; i <= n; i++)
    {
        sum[i][i] = num[i];
        dp[i][i] = 0;
    }
    // 区间长度
    for (int x = 1; x <= n; x++)
    {
        // i 区间起点
        for (int i = 1; i + x <= n; i++)
        {
            // j 区间终点
            int j = i + x;
            for (int k = i; k <= j; k++)
            {
                sum[i][j] = sum[i][k] + sum[k + 1][j];
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[i][j]);
            }
        }
    }
    
    printf("%d", dp[1][n]);
    return 0;
}