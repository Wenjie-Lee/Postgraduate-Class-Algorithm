#include <iostream>
#include <string>
using namespace std;
#define N 10002
//问题表示
string str1,str2;
int a[N],b[N];
//求解结果表示
int r[N];
void solve(int a[],int b[],int n,int m)		//求a和b相乘的结果r
{
	memset(r,0,sizeof(r));			//初始化r的所有元素为0
    for (int i=0;i<n;i++)
    {
        for (int j=0; j<m; j++)
        {
            int k=i+j;				//对应位数字相乘
            r[k] += a[i] * b[j];
            while(r[k]>9)			//有进位
            {
                r[k+1]+=r[k]/10;
                r[k] %= 10;
                k++;
            }
        }
	}
}
int main()
{
	int i;
    while (cin >> str1 >> str2)			//输入多个测试用例
    {
        for(i=0;i<str1.size();i++)		//str1转化为数字数组a
			a[i]=str1[str1.size()-1-i]-'0';
        for (i=0;i<str2.size();i++)		//str2转化为数字数组b
			b[i]=str2[str2.size()-1-i]-'0';
        solve(a,b,str1.size(),str2.size());
		int high=str1.size()+str2.size()-1;
		while (r[high]== 0 && high>0)	//求出最高非0位
			high--;
		for (i=high;i>=0; i--)			//输出结果
			cout << r[i];
		cout << endl;
    }
    return 0;
}

const int maxn = 10010;
string s1, s2;
int n1[maxn], n2[maxn], res[maxn], n1l = 0, n2l = 0;

int solve() {
	memset(res, 0, sizeof(res));
	int maxdig = 0;
	for (int i = 0; i < n1l; i++)
	{
		for (int j = 0; j < n2l; j++)
		{
			// 对应位数字相乘
			int k = i + j;
			res[k] += n1[i] * n2[j];
			while (res[k] > 9) {
				res[k + 1] += res[k] / 10;
				res[k] %= 10;
				k++;		// 一直往上进位
			}
			maxdig = max(maxdig, k);
		}
	}
	return maxdig;
}

int main() {
	while (cin >> s1 >> s2)
	{
		// 数组记录数字是从后往前
		for (int i = 0; i < s1.size(); i++)
		{
			n1[i] = s1[s1.size() - 1 - i] - '0';
			n1l++;
		}
		for (int i = 0; i < s2.size(); i++)
		{
			n2[i] = s2[s2.size() - 1 - i] - '0';
			n2l++;
		}

		int length = solve() + 1;	// k从0开始计数
		for (int i = 0; i < length; i++)
		{
			printf("%d", res[length - i - 1]);
		}
		printf("\n%d\n", length);
	}
	return 0;
}