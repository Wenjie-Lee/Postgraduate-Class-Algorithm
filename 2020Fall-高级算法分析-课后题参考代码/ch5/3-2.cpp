#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>	
using namespace std;
#define MAXL 15
//问题表示
char str[MAXL];				//输入的字符串
int n;						//输入的整数
int m;						//str的长度
char x[5];					//存放一个解
bool flag;					//判断是否有解
void swap(char &a,char &b)	//交换两个字符
{
	char tmp=a;
	a=b; b=tmp;
}

int fn(char a,int n)	//求大写字母a的n次方
{
	if (n==1)
		return a-'A'+1;
	return (a-'A'+1)*fn(a,n-1);
}
void dfs(int i)
{
	if (i==5)
	{
		if (fn(x[0],1)-fn(x[1],2)+fn(x[2],3)-fn(x[3],4)+fn(x[4],5)==n)
		{
			flag=true;
			for (int j=0; j<5; j++)		//输出解
				cout << x[j];
			cout << endl;
		}
		return;
	}
	if (flag) return;	//表示已经有结果了
	for (int j=i;j<m;j++)
	{
		swap(str[i],str[j]);
		x[i]=str[i];
		dfs(i+1);
		swap(str[i],str[j]);
	}
}
int main()
{
	while (true)
	{
		cin >> n;							//输入n
		if (n==0) break;					//n=0结束
		cin >> str;							//输入字符串
		m=strlen(str);						//求出其长度
		flag=false;							//设置有无解标志
		sort(str,str+m,greater<char>());	//按字典序递减排序
		dfs(0);								//从0开始搜索
		if (!flag)
			cout << "no solution" << endl;
	}
	return 0;
}
