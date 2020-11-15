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

// 重置visit
void init() {
    memset(visit, 0, sizeof(visit));
}

// BFS分支限界法，输出是跳数∈[0, n]，除了0跳以外，其余都要-1得翻译的个数
int bfs(int sta, int def) {
    queue<int> q;
    int ans = -1;       // -1 ，当起点加入是ans+1=0；同时-1也可以表示不连通
    bool trigger = false;
    q.push(sta);
    
    while (!q.empty())
    {
        int j = q.front();
        q.pop();
        visit[j] = true;
        ans++;
        /*
        是否到达终点，这一步同时也能用来判断两点是否连通
        题设所求，其实是两点之间的跳数问题，则跳数越少越好，所以当某路径最先到达终点时，
        当前ans即为最少跳数，跳出循环
        */
        if (j == def) {
            trigger = true;
            break;
        }

        for (int i = 0; i < n; i++)
        {
            // 没达到终点，继续遍历当前点的子结点，将子结点都加入队列
            if (!visit[i] && G[j][i]) {
                q.push(i);
            }
        }
    }
    // 若bfs完成，trigger == false, 即没有到达终点
    if (!trigger) ans = -1;
    return ans;
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
        int res = bfs(a, b);
        switch (res)
        {
        case -1:    // res = -1 即不连通
            break;
        case 0:     // res = 0 是起点终点相同的情况
            break;
        default:
            res--;  // 跳数-1=翻译的数量
            break;
        }
        printf("%d->%d: %d\n", a, b, res);
    }

    return 0;
}