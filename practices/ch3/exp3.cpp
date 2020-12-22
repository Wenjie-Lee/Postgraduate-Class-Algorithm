#include <stdio.h>
#include <malloc.h>
int ans;					//全局变量,累计逆序数
void Merge(int a[],int low,int mid,int high)	//两个相邻有序段归并
{	int i=low;
    	int j=mid+1;
    	int k=0;
	int *tmp=(int *)malloc((high-low+1)*sizeof(int));
    	while(i<=mid && j<=high) 				//二路归并：a[low..mid]、a[mid+1..high]=>tmp
    	{	if(a[i]>a[j])
        	{	tmp[k++]=a[j++];
            	ans+=mid-i+1;
        	}
        	else tmp[k++]=a[i++];
	}
    	while(i<=mid)  tmp[k++]=a[i++];
	while(j<=high)  tmp[k++]=a[j++];
	for(int k1=0;k1<k;k1++)				//tmp[0..k-1]=>a[low..high]
        a[low+k1]=tmp[k1];
	free(tmp);
}
void MergeSort(int a[],int low,int high)		//递归二路归并排序
{	if(low<high)
    	{	int mid=(low+high)/2;
        	MergeSort(a,low,mid);
        	MergeSort(a,mid+1,high);
        	Merge(a,low,mid,high);
    	}
}
void Inversion(int a[],int n)				//二路归并法求逆序数
{	ans=0;
	MergeSort(a,0,n-1);
}
void main()
{
	int a[]={3,1,4,5,2};
	int n=sizeof(a)/sizeof(a[0]);
	printf("求解结果\n");
	printf("   序列: ");
	for (int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	Inversion(a,n);
	printf("   逆序数: %d\n",ans);
}
