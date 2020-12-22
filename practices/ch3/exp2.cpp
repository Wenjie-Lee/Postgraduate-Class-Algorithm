#include <stdio.h>
//求解结果表示
int num;							//全局变量,存放众数
int maxcnt=0;						//全局变量,存放重数
void split(int a[],int low,int high,int &mid,int &left,int &right)
//以a[low..high]中间的元素为界限,确定为等于a[mid]元素的左、右位置left和right
{	mid=(low+high)/2;
	for(left=low;left<=high;left++)
		if (a[left]==a[mid])
			break;
	for (right=left+1;right<=high;right++)
		if (a[right]!=a[mid])
			break;
	right--;
}
void Getmaxcnt(int a[],int low,int high)
{	if (low<=high)					//a[low..high]序列至少有1个元素
	{	int mid,left,right;
		split(a,low,high,mid,left,right);
		int cnt=right-left+1;			//求出a[mid]元素的重数
		if (cnt>maxcnt)				//找到更大的重数
		{	num=a[mid];
			maxcnt=cnt;
		}
		Getmaxcnt(a,low,left-1);		//左序列递归处理
		Getmaxcnt(a,right+1,high);	//右序列递归处理
	}
}
void main()
{
	int a[]={1,2,2,2,3,3,5,6,6,6,6};
    int n=sizeof(a)/sizeof(a[0]);
	printf("求解结果\n");
	printf("  递增序列: ");
	for (int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
    Getmaxcnt(a,0,n-1);
	printf("  众数: %d, 重数: %d\n",num,maxcnt);
}
