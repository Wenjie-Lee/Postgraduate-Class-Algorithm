#include <stdio.h>
#include <stdlib.h>				//包含产生随机数的库函数
#include <time.h>
#define MAX 100
//问题表示
int a[MAX];
int n;
int SUM(int low,int high)			//求a[low..high]的重量
{
	int sum=0;
	for (int i=low;i<=high;i++)
		sum+=a[i];
	return sum;
}
int solve(int low,int high)			//假定伪币较真币轻
{
	if (low==high)					//只有一个硬币
		return low;
	if (low==high-1)				//只有两个硬币
	{
		printf("  硬币%d和硬币%d称重一次: ",low,high);
		if (a[low]<a[high])
		{
			printf("前者重量轻\n");
			return low;
		}
		else
		{
			printf("后者重量轻\n");
			return high;
		}
	}
	int mid=(low+high)/2;
	int sum1,sum2;
	if ((high-low+1)%2==0)			//区间内硬币个数为偶数
	{
		sum1=SUM(low, mid);
		sum2=SUM(mid+1,high);
		printf("  硬币%d-%d和硬币%d-%d称重一次: ",low,mid,mid+1,high);
	}
	else							//区间内硬币个数为奇数
	{
		sum1=SUM(low,mid-1);
		sum2=SUM(mid+1,high);
		printf("  硬币%d-%d和硬币%d-%d称重一次: ",low,mid-1,mid+1,high);
	}
	if (sum1==sum2)
	{
		printf("两者重量相同\n");
		return mid;
	}
	else if(sum1<sum2)				//假币在左区间
	{
		printf("前者重量轻\n");
		if ((high-low+1)%2==0)		//区间内硬币个数为偶数
			return solve(low,mid);
		else						//区间内硬币个数为奇数
			return solve(low,mid-1);
	}
	else							//假币在右区间
	{
		printf("后者重量轻\n");
		return solve(mid+1,high);
	}
}
void main()
{
	int n=12;
	for (int i=0;i<n;i++)
		a[i]=2;					//设置硬币重量
	srand((unsigned)time(NULL));
	a[rand()%n]=1;				//随机设置一个假币重量为1
	printf("求解过程\n");
	printf("  硬币%d是假币\n",solve(0,n-1));
}
