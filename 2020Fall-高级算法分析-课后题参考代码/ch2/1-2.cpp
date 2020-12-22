#include <stdio.h>
#include <vector>
using namespace std;
//问题表示
int n;
vector<int> item;				//采用vector容器存放整数序列（采用数组亦可）
int solve(int low, int high)	//求解回文序列问题
{
	int ans=0;
    int ie = item[low];
    int je = item[high];
    while (low<high && ie!=je)	//区间内有两个及以上数且两端数不相等
    {
        	if (ie<je)				//前面数小，前面做一次转换操作
	{
		low++;
		ie += item[low];
            	++ans;
	}
        	else					//后面数小，后面做一次转换操作
	{
		high--;
            je += item[high];
            ++ans;
        }
    }
    if (low>=high)				//区间内只有一个数或者为空
        return ans;
    else						//区间内有两个及以上数，递归处理子问题
	{
		low++;
		high--;
        return ans+solve(low,high);
	}
}
int main()
{
	int x;
	scanf("%d",&n);
    for (int i=0; i<n; i++)
	{
		scanf("%d",&x);
		item.push_back(x);
	}
	printf("%d\n",solve(0,n-1));
    return 0;
}
