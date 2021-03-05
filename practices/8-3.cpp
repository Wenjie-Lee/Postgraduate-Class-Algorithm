// practice 8-3
/*
最长下降子序列问题

*1
12
68 69 54 64 68 64 70 67 78 62 98 87
:4
*/

const int maxn = 5010;
int n, price[maxn], dp[maxn];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> price[i];

	// init 初始最低购买天数是1

	int ans = 1;		// 统计最长天数
	for (int i = 1; i < n; i++)
	{
		dp[i] = 1;
		// 统计第i天之前
		for (int j = 1; j < i; j++)
		{
			if (price[i] < price[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(dp[i], ans);
	}
	cout << ans << endl;
	return 0;
}