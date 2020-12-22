#include <stdio.h>
#define MAX 10002
//问题表示
struct Action
{
	int b;					//活动起始时间
	int e;					//活动结束时间
};
int n;
Action A[MAX];				//下标0不用
//求解结果表示
int x[MAX];					//解向量
int laste=0;				//一个方案中最后兼容活动的结束时间
int sum=0;					//一个方案中所有兼容活动的时间和
int maxsum=0;				//最优方案中所有兼容活动的时间和
void swap(int &x,int &y)	//交换x、y
{	int tmp=x;
	x=y; y=tmp;
}
void dfs(int i)							//搜索活动问题最优解
{
	if (i>n)							//到达叶结点,产生一种调度方案
    {
		if (sum>maxsum)
			maxsum=sum;
	}
	else
	{
		for(int j=i; j<=n; j++)				//没有到达叶结点,考虑i到n的活动
		{	//第i层结点选择活动x[j]
			int sum1=sum;					//保存sum,laste以便回溯
			int laste1=laste;
			if (A[x[j]].b>=laste)			//活动x[j]与前面兼容
			{
				sum+=A[x[j]].e-A[x[j]].b;	//累计活动x[j]的执行时间
				laste=A[x[j]].e;			//修改本方案的最后兼容时间
			}
			swap(x[i],x[j]);				//排序树问题递归框架:交换x[i],x[j]
			dfs(i+1);						//排序树问题递归框架:进入下一层
			swap(x[i],x[j]);				//排序树问题递归框架:交换x[i],x[j]
			sum=sum1;						//回溯
			laste=laste1;					//即撤销第i层结点对活动x[j]的选择,以便再选择其他活动
		}
	}
}
int main()
{
	int j;
	scanf("%d",&n);
	for (j=1; j<=n; j++)
		scanf("%d%d",&A[j].b,&A[j].e);	//输入p,k
	for (j=1;j<=n;j++)					//x数组初始化
		x[j]=j;
	dfs(1);
	printf("%d\n",maxsum);
    return 0;
}



