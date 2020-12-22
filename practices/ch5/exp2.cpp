#include <stdio.h>
#include <math.h>
#define N 10  
bool used[N+1];					//used[i]=true表示数字i可以使用
int a[9];						//存放3×3个方格
int count=0;					//统计解个数
int Checkmatrix[][3]={ {-1},{0,-1},{1,-1},{0,-1},{1,3,-1},
				 {2,4,-1},{3,-1},{4,6,-1},{5,7,-1} };  
void dispasolution(int a[])			//输出一个解
{	int i,j;
	printf("解%d\n",++count);
	for (i=0;i<3;i++)
	{	for (j=0;j<3;j++)
			printf("%3d",a[3*i+j]);
		printf("\n");
	}
}
bool isPrime(int m)				//判断m是否为素数
{	bool flag=true;
	for (int i=2;i<=sqrt(m);i++)
		if (m%i==0)
			return false;
	return true;
} 
bool Check(int pos)				//检查a中pos位置的相邻两个方格内的数字之和是否为素数
{	int i,j;
	if (pos<0) return 0;
	for (i=0;(j=Checkmatrix[pos][i])>=0;i++)
		if (!isPrime(a[pos]+a[j]))	//有一个不是素数,则返回false
			return false;
	return true; 
}
int selectnum(int start)			//从start位置开始选择一个没有使用的数字
{	for (int j=start;j<=N;j++)
		if (used[j]) return j;
	return 0;					//没有合适的数字返回0
} 
int extend(int pos)				//扩展:为pos位置选择一个没有使用的数字,pos++
{	a[++pos]=selectnum(1);		//扩展过程都是从1开始选择数字的
	used[a[pos]]=0;  			//标志该数字已使用
	return pos;  
}
int change(int pos)				//调整：从pos开始回溯
{	int j;
	//为pos位置选择另外一个数字,为了避免重复,是从原数字的下一个数字开始选取的
	//若不能为pos选择一个数字,则回溯,即恢复a[pos]为可以使用的,再执行pos--
	while (pos>=0 && (j=selectnum(a[pos]+1))==0)
		used[a[pos--]]=true;
	if (pos<0) return -1;			//全部回溯完毕,返回-1算法结束
	used[a[pos]]=true;			//为pos位置找到一个没有使用的数字j
	a[pos]=j;					//pos位置放置数字j
	used[j]=false;				//标识数字j已经使用过
	return pos;					//返回该回溯的新位置  
}
void solve()					//求解算法
{	bool ok=true;				//当前填数是否有效
	int pos=0;					//从位置0开始
	a[pos]=1;					//在pos位置填入1
	used[a[pos]]=0;				//标志数字1已经使用过
	do
	{	if (ok)
		{	if (pos==8)
			{	dispasolution(a);
				pos=change(pos);
			}
			else pos=extend(pos); 
		}
		else
			pos=change(pos);
		ok=Check(pos);
	} while (pos>=0);
}
void main() 
{	for (int i=1;i<=N;i++)			//初始化,所有数字均可以使用
		used[i]=true;
	solve();
	printf("count=%d\n",count);	//输出数字填法总数
}
