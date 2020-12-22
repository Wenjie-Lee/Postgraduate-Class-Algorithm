#include <stdio.h>
#include <string.h>
#define MAXN 1005
//问题表示
int n;
int a[MAXN];
//求解结果表示
int ans;				//可以产生的幸运的袋子数
//求解过程表示
int times[MAXN];			//times[i]表示元素t出现的次数
int m;				//times数组中元素个数(不同号码球的个数)
void init()
{
	int t;
	m=0;
	memset(times,0,sizeof(times));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        if(times[t]==0)
            a[++m]=t;
        times[t]++;
    }
}
void dfs(int i,int sum,int mult)		//深度优先搜索
{
    if (i>m) return;
    dfs(i+1,sum,mult);			//不选择a[i]号码的球
    for(int j=1;j<=times[a[i]];j++)	//选择a[i]号码的球，选中j个
    {
        sum+=a[i];
        mult*=a[i];
        if(i!=1 && mult>=sum) break;
        if(sum>mult) ans++;		//找到一个解
        dfs(i+1,sum,mult);
    }
}
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		init();
		ans=0;
		dfs(1,0,1);
		printf("%d\n",ans);
	}
	return 0;
}

