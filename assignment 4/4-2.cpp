#include <iostream>
#include <string.h>
#include <functional>
#include <algorithm>
using namespace std;
#define MAX 201
//问题表示
int n,m;
int a[MAX];
//求解结果表示
int ans;
void solve()
{
	int d[MAX];
	sort(a,a+n,greater<int>());	//从大到小排序区间
	for(int i=0; i<n-1;i++)	//求出各个间隔
		d[i]=a[i]-a[i+1]-1;
	sort(d,d+n-1,greater<int>());	//从大到小排序间隔
	if (m>n)			//如果m>n,直接输出n
		ans=n;
	else
	{
		int num=1;	//累计线段数
		ans=a[0]-a[n-1]+1;	//初始线段总长
		int j=0;
		while(num<m && d[j]>0)
		{
			num++;
			ans=ans-d[j];	//减去间隔
			j++;
		}
	}
}
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
		solve();
		printf("%d\n", ans);
	}
    return 0;
}

