#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1001
//问题表示
int a[MAX]={10,1,10,20,30,20};
int n=6;
//求解结果表示
int bestd;					//出现次数最多的最小数
int maxn=0;					//出现最多的次数
void solve()					//求解出现次数最多的数
{	sort(a,a+n);				//按整数值递增排序
	int pred=a[0];
	int num=1;
	int i=1;
	while (i<n)
	{	while (i<n && a[i]==pred)
		{	num++;
			i++;
		}
		if (num>maxn)			//比较求maxn
		{	bestd=pred;
			maxn=num;
		}
		pred=a[i];				//a[i]!=pred的情况
		num=1;
		i++;
	}
}
int main()
{	//添加输入测试用例的代码
	solve();
	printf("%d\n",bestd);		//输出10
	return 0;
}
