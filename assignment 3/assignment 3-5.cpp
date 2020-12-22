// assignment 3-5

/*
算法思想：动物的通信关系可用一个无向图来表示。两种动物是否能相互通信是无向图的连通问题，
        能通信则二者在同一个连通子图内。翻译的个数是无向图两个顶点求最短路径问题。

输入样例1：
3 2
0 1
1 2
2
0 0
0 2
样例输出1：
0
1
输入样例1：  // 4个点依次有边相连
4 3
0 1
1 2
2 3
1
0 3 
样例输出1：  // 0->3，有1，2两个翻译
2
*/

const int maxn = 1000;  // 实际的限制是200000
int n, m, k;
int G[maxn][maxn];
bool visit[maxn];
struct node {		// 用来记录各个点，当前路径长度
	int u, length;
};
// 重置visit
void init() {
    memset(visit, 0, sizeof(visit));
}

// BFS分支限界法
int bfs(int sta, int def) {
    if (sta == def) return 0;
    node e, e1;
    queue<node> q;
    e.u = sta, e.length = 0;
    bool trigger = false;
    q.push(e);
    
    while (!q.empty())
    {
        e1 = q.front();
        q.pop();
        visit[e1.u] = true;
        if (e.u == def) 
	return e.length - 1;
        /*
        是否到达终点，这一步同时也能用来判断两点是否连通
        题设所求，其实是两点之间的跳数问题，则跳数越少越好，所以当某路径最先到达终点时，
        当前ans即为最少跳数，跳出循环
        */
        for (int i = 0; i < n; i++)
        {
            // 没达到终点，继续遍历当前点的子结点，将子结点都加入队列
            if (!visit[i] && G[j][i]) {
	e1.u = i, e1.length = e.length + 1;
                q.push(e1);
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &n, &m);
    int a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        // 表示两种动物可以互相通信
        G[a][b] = G[b][a] = 1;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &a, &b);
        init();
        printf("%d->%d: %d\n", a, b, bfs(a, b));
    }

    return 0;
}