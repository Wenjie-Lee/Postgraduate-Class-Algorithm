// assignment 4-4

/*
边界：
    (1) dp[i]初始化为10011，即最大跳数
    (2) dp[1]=1，即跳到第一个桩子上记一次
状态转换方程：
    dp[i + (x=range(1, p[i]))] = min(自身, dp[i]+1)
    在本次能跳到的桩子上从前到后更新

*1
5
2 0 1 1 1
:4
*2
5
6 0 1 1 1
：2
*3
5
1 1 1 0 0
：-1
*/

const int maxn = 10010;
int n, p[maxn], dp[maxn];
int main() {
    scanf("%d", &n);
    // 其实p[n]没什么用，因为跳到第n个桩子就算成功了
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    // boundary init，n+1次跳跃是不可能的
    for (int i = 1; i <= n; i++)
        dp[i] = n + 1;
    dp[1] = 1;
    // 不取n，因为在前面的n-1次遍历中已经更新了dp[n]
    for (int i = 1; i < n; i++)
    {
        // 跳过了p[i]=0，即力量为0，不能跳，也不能对后面进行更新
        for (int x = 1; x <= p[i]; x++)
        {
            // 超过范围，跳出
            if (i + x > n) break;
            dp[i + x] = min(dp[i + x], dp[i] + 1);
        }
    }
    if (dp[n] == n + 1)
        printf("-1");
    else
        printf("%d", dp[n]);
    return 0;
}