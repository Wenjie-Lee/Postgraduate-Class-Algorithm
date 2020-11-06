// assignment 3-3

/*
完全图：图中任意两个顶点都直接相连的图称为完全图
最大团：顶点个数最多的完全子图

算法思想：运用DFS思想，遍历图G的所有顶点
        （1） 以第i个点起始，遍历得到一个连通子图，且判断该子图是否是完全子图，若是则记录结果；
        （2） 剪枝技巧：
            （a） 若剩余的未遍历的顶点数目小于当前结果子图顶点数目，就不再深入；
            （b） dfs函数中，从当前i点往后开始判断是否加入vec，不用考虑i和i之前的点
            （c） dfs函数中，当前子图顶点数 + 未访问顶点数 < 当前答案顶点数时，剪枝不再深入

输入样例1：
5 6
1 2
2 3
2 4
3 4
3 5
4 5
0 0
样例输出1：
3
输入样例2：
5 7
1 2
2 3
1 3
1 4
1 5
4 5
3 5
0 0
样例输出2：
3
输入样例3：
5 4
1 2
2 3
3 4
4 5
0 0
样例输出3：
2
*/

const int maxn = 51;            // 最多50个顶点
int n, m, max_vertex = 0, graph[maxn][maxn];    // 邻接矩阵graph
int unvisit;                    // 当前有多少个顶点未被访问
bool visit[maxn];
vector<int> vec;

// 加入该点后，vec包含的子图是否为完全子图
bool is_complete_subgraph(int i) {
    bool trigger = true;
    for (auto v : vec) {
        // 若点i和vec中某一点不直接相连
        if (!graph[i][v]) {
            trigger = false;
            break;
        }
    }
    return trigger;
}

void dfs(int i) {
    vec.push_back(i);
    // 从i+1点开始，之前的点都已经判定过了
    for (int j = i+1; j <= n; j++)
    {
        if (graph[i][j] == 1 && !visit[j]) {
            // 当前子图顶点数 + 未访问顶点数 >= 当前答案顶点数时，才会继续深入
            if (vec.size() + unvisit < max_vertex) continue;
            visit[j] = true;
            unvisit--;
            // 当加入点j后，仍为完全子图时，才继续深入
            if (is_complete_subgraph(j)) {
                dfs(j);
                max_vertex = max(max_vertex, int(vec.size()));
            }
            visit[j] = false;
            unvisit++;
        }
    }
}

int main() {
    do
    {
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0) break;

        // init
        max_vertex = 0;
        unvisit = n;
        memset(graph, 0, sizeof(graph));
        memset(visit, 0, sizeof(visit));

        int a, b;
        // 读取m条边的信息
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            graph[a][b] = graph[b][a] = 1;
        }
        // 遍历所有顶点，执行dfs，确保访问到无向图G中的所有不连通子图
        for (int i = 1; i <= n; i++)
        {
            // 剩余的未访问点的个数 < 当前答案，就不再进行下去了
            if (unvisit < max_vertex) break;
            if (!visit[i]) {
                visit[i] = true;
                unvisit--;
                dfs(i);
                vec.clear();
            }
        }
        printf("max vertex: %d\n", max_vertex);
    } while (true);

    return 0;
}