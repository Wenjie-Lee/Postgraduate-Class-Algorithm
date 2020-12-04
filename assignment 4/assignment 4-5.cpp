// assignment 4-5

/*
化为01背包问题
从n个整数（每个数的重量和价值相等）中选取k个数，使k个数的重量和不超过sum的情况下，
k个数的价值和最大（若有解，其实也是sum），当有解时，dp[sum]=sum
边界：
        (1) dp[0] = 0
状态转换方程：
        dp[v] = max(dp[v], dp[v-w[i]]) + c[i]; (c和w在本题其实是一个数组)

*1
5 15
5 5 10 2 3
:4
*2
8 15
1 2 8 7 2 4 11 15
:7
*3
7 14
1 8 7 2 4 11 15
:3
*4
6 14
1 8 7 4 11 15
:0
*/
const int maxn = 1010;
int n, sum, a[maxn], dp[maxn];
bool choice[maxn][maxn];
struct node {
    int idx, local_sum;
};
int main() {
    scanf("%d%d", &n, &sum);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    // boundary init

    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= a[i]; j--)
        {
            if (dp[j] <= dp[j - a[i]] + a[i]) {
                dp[j] = dp[j - a[i]] + a[i];
                choice[i][j] = true;
            }
            else {
                choice[i][j] = false;
            }
        }
    }
    int num = 0;
    queue<node> q;
    node no;
    for (int i = n; i >= 1; i--)
    {
        if (choice[i][sum]) {
            no.idx = i;
            no.local_sum = sum - a[i];
            //printf("push: idx:%d, num:%d, localsum:%d\n", i, a[i], no.local_sum);
            q.push(no);
        }
    }
    while (!q.empty()) {
        node no1= q.front();
        q.pop();
        int idx = no1.idx, local_sum = no1.local_sum;
        if (local_sum == 0) {
            num++;
            continue;
        }
        for (int j = idx - 1; j >= 1; j--)
        {
            if (choice[j][local_sum]) {
                no1.idx = j;
                no1.local_sum -= a[j];
                // printf("init: idx:%d, num:%d, localsum:%d  ", idx, a[idx], local_sum);
                // printf("push: idx:%d, num:%d, localsum:%d\n", j, a[j], no1.local_sum);
                q.push(no1);
                no1.idx = idx;
                no1.local_sum += a[j];
            }
        }
    }
    printf("%d", num);
    return 0;
}