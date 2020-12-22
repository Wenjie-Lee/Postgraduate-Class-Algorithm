#include<iostream>
#include<queue>
#include<string>
using namespace std;
#define MAXN 10
#define MAXM 10
//问题表示
char map[MAXN][MAXM]={"...#..","......","#*##..","..##.#","..X...",".@#..."};
int n=6,m=6;
int H[4] = {0,1,0,-1};				//水平偏移量,下标对应方位号0～3
int V[4] = {-1,0,1,0};				//垂直偏移量
int state[MAXN][MAXM][MAXN][MAXM];	//4维数组表示人和箱子的位置状态,开始全为0

struct NodeType
{
    int px,py;		//人的位置
	int bx,by;		//箱子的位置
	int step;		//移动步数
};
int personx,persony,boxx,boxy,endx,endy; //分别表示当前人的位置，盒子的位置，终点位置

bool Bound(int x,int y)	//检查(x,y)位置是否合法：有效且可以走
{
    if (x<0 || y<0 || x>=n || y>=m || map[x][y]=='#')
        return true;	//不合法返回true
    else
        return false;	//合法返回false
}
int BFS()
{
	NodeType rnode,curnode,subnode;
    queue<NodeType> qu;			//状态队列
	rnode.px=personx;
	rnode.py=persony;
	rnode.bx=boxx;
	rnode.by=boxy;
	rnode.step=0;
	qu.push(rnode);
    state[personx][persony][boxx][boxy] = 1;//当前其实状态位置设步数为1

    while (!qu.empty())			//队列不空循环
    {
        curnode=qu.front();		//获取首元素
        qu.pop();				//首元素弹出
        if (curnode.bx==endx && curnode.by==endy)
            return state[curnode.px][curnode.py][curnode.bx][curnode.by]-1;//如果箱子在终点，结束，返回步数
        for (int k=0; k<4; k++)//四个方向开始搜索了
        {
            //先更新人的位置
            int px=curnode.px+H[k];
            int py=curnode.py+V[k];
            if (Bound(px,py))
                continue;//如果这个位置非法，探寻其它方向
            if (px==curnode.bx && py==curnode.by)		//如果此时人的位置与箱子的位置重合，说明人应当推动了箱子
            {
                if (Bound(curnode.bx + H[k], curnode.by + V[k]))
                    continue;//如果箱子移动的位置不合法，则重新探寻其它方向
                state[px][py][curnode.bx + H[k]][curnode.by + V[k]] =
                    state[curnode.px][curnode.py][curnode.bx][curnode.by] + 1;//箱子推动，则人和箱子位置改变，记录新状态
				subnode.px=px;
				subnode.py=py;
				subnode.bx=curnode.bx+H[k];
				subnode.by=curnode.by+V[k];
                qu.push(subnode);//新状态入栈

            }
            else//人没有推动箱子
            {
                if (state[px][py][curnode.bx][curnode.by])//如果移动后的状态出现过，则重新搜索新方向
                    continue;
                state[px][py][curnode.bx][curnode.by] = state[curnode.px][curnode.py][curnode.bx][curnode.by] + 1;
                //没有走过这条路就走着试试
				subnode.px=px;
				subnode.py=py;
				subnode.bx=curnode.bx;
				subnode.by=curnode.by;
                qu.push(subnode);				//更新状态
            }
        }
    }
    return -1;//如果所有位置都试过了，没有找到，说明不存在
}
int main()
{
	memset(state,0,sizeof(state));
    for (int i = 0; i < n; i++)		//初始化人，箱子，终点的位置
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j]=='*')		//箱子位置
            {
                boxx = i;
                boxy = j;
            }
            else if (map[i][j] == 'X')	//人的位置
            {
                personx = i;
                persony = j;
            }
            else if (map[i][j] == '@')	//目标位置
            {
                endx = i;
                endy = j;
            }
        }
    }
    cout << BFS() << endl;
    return 0;
}
