#include<stdio.h>
#define MAX 30
//问题表示
int n=2;							//湖的个数
int h=1;							//可用时间
int fi[MAX]={0,10,1};				//最初钓鱼量,数组下标0不用
int di[MAX]={0,2,5};				//单位时间鱼的减少量,数组下标0不用
int ti[MAX]={0,2};					//ti[i]为湖i到湖i+1的时间,数组下标0不用
int cfi[MAX];						//保存fi
//求解结果表示
struct NodeType
{	int num[MAX];					//各个湖的钓鱼时间
	int max;						//最多的钓鱼量
} Lake[MAX];						//Lake[i]表示经过最后一个湖i的结果
int maxlast;						//最多钓鱼量时最后经过湖的编号
int GetMax(int p[],int i,int j)			//求p[i..j]中最大元素的下标
{	int maxi=i;						//最大元素下标初始化
	for (int k=i+1;k<=j;k++)
		if (p[maxi]<p[k])	//比较
			maxi=k;
	return maxi;
}
void solve()						//求解钓鱼问题
{	int i,j,t,restT;
	int T=60*h;					//可用时间总时间
	for (i=1;i<=n;i++)				//枚举每一个可能的结束湖位置
	{	restT=T;					//剩下的时间
		for (j=1;j<=i;j++)			//所有走过的湖是1,2,…,i
		{	cfi[j]=fi[j];				//初始化cfi
			if (j<i)
				restT-=5*ti[j];		//减去到达湖i路上走路的时间
		}
		t=0;
		while (t<restT)				//考虑所有的钓鱼时间
		{	int k=GetMax(cfi,1,i);	//找到钓鱼量最多的湖k
			Lake[i].max+=cfi[k];		//在湖k中钓一个单位时间的鱼
			Lake[i].num[k]+=5;		//湖i的钓鱼时间增加一个单位时间
			if (cfi[k]>=di[k])			//修改湖k下一个单位时间的钓鱼量
				cfi[k]-=di[k];
			else
				cfi[k]=0;
			t+=5;					//增加一个单位时间5
		}
	}
}
int main()
{	int i,j;
	for (i=1;i<=n;i++)				//Lake数组初始化
	{	Lake[i].max=0;
		for (j=0;j<=n;j++)
			Lake[i].num[j]=0;
	}
	solve();
	printf("求解结果\n");
	maxlast=1;
	for (i=2;i<=n;i++)
		if (Lake[i].max>Lake[maxlast].max)
			maxlast=i;
	for (i=1;i<=n;i++)
		printf("    在湖%d钓鱼时间为%d分钟\n",i,Lake[maxlast].num[i]);
	printf("  总的钓鱼量: %d\n",Lake[maxlast].max);
    return 0;
}
