#include <stdio.h>
#include <stdlib.h>				//包含产生随机数的库函数
#include <time.h>
#define MAX 102
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
	int sum1,sum2;
	if (low==high)					//只有一个硬币
		return low;
	if (low==high-1)				//只有两个硬币
	{
		printf("  硬币%d和硬币%d称重一次: ",low,high);
		if (a[low]<a[high])
		{
			printf("硬币%d重量轻\n",low);
			return low;
		}
		else
		{
			printf("硬币%d重量轻\n",high);
			return high;
		}
	}
	else if (low==high-2)			//只有3个硬币
	{
		printf("  硬币%d和硬币%d称重一次: ",low,low+1);
		sum1=a[low];
		sum2=a[low+1];
		if (sum1<=sum2)
		{
			printf("硬币%d重量轻\n",low);
			return low;
		}
		else if (sum1>sum2)
		{
			printf("硬币%d重量轻\n",low+1);
			return low+1;
		}
		else
		{
			printf("两者重量相同\n");
			return low+2;
		}
	}
	int len=(high-low+1)/3;			//每个区间的长度
	int mid1=low+len-1;				//区间1:a[low..mid1]
	int mid2=mid1+len;				//区间2:a[mid1+1,mid2],区间3:a[mid2+1..high]
	sum1=SUM(low,mid1);
	sum2=SUM(mid1+1,mid2);
	printf("  硬币%d-%d和硬币%d-%d称重一次: ",low,mid1,mid1+1,mid2);
	if (sum1==sum2)
	{
		printf("两者重量相同\n");
		return solve(mid2+1,high);	//假币在区间3
	}
	else if (sum1<sum2)				//假币在区间1
	{
		printf("前者重量轻\n");
		return solve(low,mid1);
	}
	else							//假币在区间2
	{
		printf("后者重量轻\n");
		return solve(mid1+1,mid2);
	}
}
void main()
{
	int n=100;
	for (int i=0;i<n;i++)
		a[i]=2;					//设置硬币重量
	srand((unsigned)time(NULL));
	a[rand()%n]=1;				//随机设置一个假币重量为1
	printf("求解过程\n");
	printf("  硬币%d是假币\n",solve(0,n-1));
}
