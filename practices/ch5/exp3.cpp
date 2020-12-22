#include <stdio.h>
#include <vector>
using namespace std;
//问题表示
int n=5,r=3;							//全局变量
void disppath(vector<int> path)			//输出一个组合
{	for (int j=0;j<path.size();j++)
		printf("  %d",path[j]);
	printf("\n");
}
void dfs(vector<int> path,int i,int num)	//求解算法
{
	if (num==r)
		disppath(path);
	for (int j=i;j<=n;j++)
	{
		path.push_back(j);			//选择元素i
		dfs(path,j+1,num+1);		
		path.pop_back();			//回溯:不选择元素i
	}
}
void main()
{
	vector<int> path;				//存放一个解
	printf("n=%d,r=%d的所有组合如下:\n",n,r);
	dfs(path,1,0);
}
