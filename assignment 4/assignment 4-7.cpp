// assignment 4-7

/*
满足（A <= B || A % B != 0） => A 是 B 的倍数时不满足

*1
2 2
:3
*2
3 2
:4
*3
3 3
:15
*/
const int maxn = 11, maxk = 100010, modnum = 1000000007;
int n, k, dp[maxn][maxk];
int main() {
    scanf("%d%d", &n, &k);

    // boundary init
    for (int i = 1; i <= k; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        int sum = 0;
        // 先把所有的都加起来， j就是所选的数，1<=j<=k
        for (int j = 1; j <= k; j++)
        {
            sum += dp[i - 1][j];
            sum %= modnum;
        }
        // 再对各个j将不满足条件的都删去， 即A是B的倍数的情况
        for (int j = 1; j <= k; j++)
        {
            int sum1 = 0, m = j * 2;
            while (m <= k)
            {
                sum1 += dp[i - 1][m];
                sum1 %= modnum;
                m += j;
            }
            dp[i][j] = (sum - sum1 + modnum) % modnum;
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
        ans = (ans + dp[n][i]) % modnum;
    printf("%d", ans);
    return 0;
}