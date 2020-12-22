#include <iostream>
#include <string.h>
#include <string>
using namespace std;
#define MAXL 18
#define MAXN 10001
//问题表示
int n;
string str;
//求解结果表示
long dp[MAXL][MAXN];
long solve()
{
	int newj;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= str.length(); i++)
	{
		for (int j = 0; j < n; j++)				//余数从可能是0到n-1
		{
			if (str[i - 1] == 'X')				//当前位数是不确定的
			{
				for (int k = 0; k <= 9; k++)	//试探K的取值0到9
				{
					newj = (j * 10 + k) % n;
					dp[i][newj] += dp[i - 1][j];
					printf("dp[%d][%d]+=dp[%d][%d]=>%d\n", i, newj, i - 1, j, dp[i][newj]);
				}
			}
			else								//当前位数是确定的
			{
				newj = (j * 10 + (str[i - 1] - '0')) % n;
				dp[i][newj] += dp[i - 1][j];
				printf("dp[%d][%d]+=dp[%d][%d]=>%d\n", i, newj, i - 1, j, dp[i][newj]);
			}
		}
	}
	return dp[str.length()][0];
}
int main()
{
	cin >> str;
	cin >> n;
	cout << solve() << endl;
	return 0;
}
