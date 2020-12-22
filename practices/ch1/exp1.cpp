#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 10
void randa(int a[],int n)		//产生n个1至20的随机数
{
	int i;
	for (i=0;i<n;i++)
		a[i]=rand()%20+1;
}
void MaxMin(int a[],int n,int &comp)	//求最大最小元素和比较次数
{
	int i,max,min;
	comp=0;
	max=min=a[0];
	for (i=1;i<n;i++)
	{
		comp++;
		if(a[i]>max)
			max=a[i];
		else
		{
			comp++;
			if(a[i]<min)
				min=a[i];
		}
	}
	for (i=0;i<n;i++)
		printf("%3d",a[i]);
	printf(" : 最大值=%d,最小值=%d,比较次数=%d\n",max,min,comp);
}
void main()
{
	int a[MAXN];
	int m,sumcomp=0,comp,count=0;
	srand((unsigned)time(NULL));
	for (m=1;m<=10;m++)
	{
		printf("第%2d组: ",++count);
		randa(a,10);
		MaxMin(a,10,comp);
		sumcomp+=comp;
	}
	printf("平均比较次数=%g\n",1.0*sumcomp/10);
}
