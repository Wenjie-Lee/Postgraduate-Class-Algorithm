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
    // 区间长度，从2开始会有合并动作
    for (int x = 2; x <= n; x++)
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

/*
另一种情况：n堆石子圆形排列，首尾相接。每次选相邻的两堆合并
    则dp(i，j)的含义就要改变为：从第i堆开始，往后合并j堆的最小花费
    sum(i，j)的含义是从第i堆开始，往后合并j堆的石子数量
*/
const int maxn = 210, maxc = 0x3f3f3f3f;
int n, num[maxn], dp[maxn][maxn];

int sumnum(int i, int j) {
    int ans = 0;
    for (; j > 0; j--, i++)
    {
        if (i > n)
            i %= n;
        ans += num[i];
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);

    fill(dp[0], dp[0] + maxn * maxn, maxc);

    // boundary init
    for (int i = 1; i <= n; i++)
    {
        // 初始化时第二维为1时，表示仅有自己一堆
        dp[i][1] = 0;
    }
    // 合并的堆数
    for (int v = 2; v <= n; v++)
    {
        // i 区间起点
        for (int i = 1; i + v <= n; i++)
        {
            // j表示从i起合并j堆
            for (int k = 1; k < v; k++)
                dp[i][v] = min(dp[i][v], dp[i][k] + dp[(i + k - 1) % n + 1][v - k] + sumnum(i, v));
        }
    }

    printf("%d", dp[1][n]);
    return 0;
}