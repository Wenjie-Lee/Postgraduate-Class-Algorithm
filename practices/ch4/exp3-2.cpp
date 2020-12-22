//非递归版本
#include <stdio.h>
#include <vector>
#include <stack>
#include <string>
using namespace std;
//问题表示
vector<vector<char> > board;			//存放面板
int m;									//面板m行
int n;									//面板n列
struct Position							//位置结构体
{
    int x;
    int y;
    Position(int x1,int y1): x(x1), y(y1) {} //构造函数
};
void dispboard()		//输出面板
{
	for(int i=0; i<m; i++)
	{
		printf("   ");
		for(int j=0; j<n;j++)
			printf("%c ",board[i][j]);
		printf("\n");
	}
}
void DFS(int i,int j,int m,int n)
{
	stack<Position *> st;
	Position *pos = new Position(i,j);
	st.push(pos);						//初始位置进栈
	board[i][j]='*';					//进栈位置的值改为'*',避免重复搜索
	while(!st.empty())					//栈不空循环
	{
		Position *curp=st.top();		//取栈顶位置方块curp
		if (curp->x>0 && board[curp->x-1][curp->y]=='O')
		{
			Position *up=new Position(curp->x-1,curp->y);
			st.push(up);
			board[up->x][up->y]='*';
			continue;
		}
		if(curp->x<m-1 && board[curp->x+1][curp->y]=='O')
		{
			Position *down = new Position(curp->x+1,curp->y);
			st.push(down);
			board[down->x][down->y]='*';
			continue;
		}
		if(curp->y>0 && board[curp->x][curp->y-1]=='O')
		{
			Position *left = new Position(curp->x,curp->y-1);
			st.push(left);
			board[left->x][left->y]='*';
			continue;
		}
		if(curp->y<n-1 && board[curp->x][curp->y+1]=='O')
		{
			Position *right = new Position(curp->x,curp->y+1);
			st.push(right);
			board[right->x][right->y]='*';
			continue;
		}
		delete curp;			//释放退栈的结点
		st.pop();				//栈顶方块没有路径时退栈
    }
}
void solve()						//问题求解算法
{
	int i,j;
	for(i=0; i<m; i++)
		for(j=0; j<n;j++)
			if(board[i][j]=='O')
			{
				if(i==0 || i==m-1 || j==0 || j==n-1)
					DFS(i,j,m,n);
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
