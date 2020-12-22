//递归版本
#include <stdio.h>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int H[4] = {0, 1, 0, -1};			//水平偏移量,下标对应方位号0～3
int V[4] = {-1, 0, 1, 0};			//垂直偏移量
//问题表示
vector<vector<char> > board;		//存放面板
int m;								//面板m行
int n;								//面板n列
void dispboard()					//输出面板
{
	int m=board.size();
	int n=board[0].size();
	for(int i=0; i<m; i++)
	{
		printf("   ");
		for(int j=0; j<n;j++)
			printf("%c ",board[i][j]);
		printf("\n");
	}
}
void DFS(int i,int j)				//从'O'位置深度优先遍历
{
	int ni,nj;
	board[i][j]='*';				//将试探位置值改为'*',避免重复搜索
	for (int k=0;k<4;k++)			//试探每一个方位
	{
		ni=i+V[k]; nj=j+H[k];		//求相邻的新位置(ni,nj)
		if(ni>=0 && ni<m && nj>=0 && nj<n && board[ni][nj]=='O')
		{	//若(ni，nj)位置有效并且为'O'
			board[ni][nj]='*';		//将新位置值改为'*'
			DFS(ni,nj);;			//从新位置出发查找'O'
		}
	}
}
void solve()						//问题求解算法
{
	int i,j;
	if(board.empty() || board[0].empty())
		return;
	for(i=0; i<m; i++)
		for(j=0; j<n;j++)
			if(board[i][j]=='O')
			{
				if(i==0 || i==m-1 || j==0 || j==n-1)
					DFS(i,j);	//从边界上的'O'出发查找
			}
	printf("DFS后的面板:\n"); dispboard();
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
		{
			if(board[i][j]=='O')		//将'O'改为'X'
				board[i][j]='X';
			else if(board[i][j]=='*')	//将'*'恢复为'O'
				board[i][j]='O';
        }
}
void main()
{
	string str[]={"XXXX","XOOX","XXOX","XOXX"};
	m=4; n=4;
	for (int i=0;i<m;i++)
	{
		vector<char> s;
		for (int j=0;j<n;j++)
			s.push_back(str[i][j]);
		board.push_back(s);
	}
	printf("原始面板:\n"); dispboard();
	solve();
	printf("最后面板:\n"); dispboard();
}
