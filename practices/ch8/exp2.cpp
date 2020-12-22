#include <iostream>
#include <string>
using namespace std;
#define MAXN 101
#define INF 0x3f3f3f3f							//∞
#define min(x,y) ((x)<(y)?(x):(y))
int Minbrack(string str)							//求使str匹配所需添加的最小括号数
{	int dp[MAXN][MAXN];
	memset(dp,0,sizeof(dp));						//dp数组元素初始化为0
	int n=str.size();
	for(int i=0; i<n; ++i)							//一个括号需要添加1个匹配的括号
		dp[i][i]=1;
	for(int len=1; len<n; ++len)						//考虑长度为len的子序列
		for(int i=0; i<=n-len; ++i)					//处理[i..j]的子序列
		{	int j=len+i;
			dp[i][j]=INF;						//首先设置为∞
			if ((str[i]=='(' && str[j]==')') || (str[i]=='[' && str[j]==']')
			   || (str[i]=='{' && str[j]=='}') )			//考虑情况(1)
				dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
			else if (str[i]=='(' || str[i]=='[' || str[i]=='{')	//考虑情况(2)
				dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
			else if (str[j]==')' || str[j]==']' || str[j]=='}') 	//考虑情况(3)
				dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
			for (int k=i;k<j;++k)					//合并
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
		}
	return dp[0][n-1];
}
void main()
{
	string str="(}(}";
	cout << "求解结果" << endl;
	cout << "    字符串: " << str << endl;
	cout << "    需添加最少括号数: " << Minbrack(str) << endl;
	str="({)}()]";
	cout << "    字符串: " << str << endl;
	cout << "    需添加最少括号数: " << Minbrack(str) << endl;
}
