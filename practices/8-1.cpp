// practice 8-1
/*

动态规划思想：
	初始化：dp[i][j] = inf;
	状态转移：dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + g[i][j], 当i,j点左边和上边有点时；
			当i,j点左边和上边不全有点时，直接用前置点更新；
			dp[0][0] = g[0][0]

*1
4
1 3 5 9
8 1 3 4
5 0 6 1
8 8 4 0
:12

*2
5
1 1 0 1 1
2 0 0 0 0
3 0 0 3 3
4 4 4 4 4
5 5 5 5 5
:14
*/

const int MAXN = 10, INF = 99999999;
int n, g[MAXN][MAXN], dp[MAXN][MAXN];

bool valid(int i, int j) {
	if (i < 0 || i == n || j < 0 || j == n)
		return false;
	return true;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];
	// boundary init
	fill(dp[0], dp[0] + MAXN * MAXN, INF);
	//dp[0][0] = g[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (valid(i - 1, j) && valid(i, j - 1))
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + g[i][j];
			else if (valid(i - 1, j))
				dp[i][j] = dp[i - 1][j] + g[i][j];
			else if (valid(i, j - 1))
				dp[i][j] = dp[i][j - 1] + g[i][j];
			else
				dp[i][j] = g[i][j];	// 只有dp[0][0]会用到这一步
		}
	}
	cout << dp[n - 1][n - 1] << endl;
	return 0;
}