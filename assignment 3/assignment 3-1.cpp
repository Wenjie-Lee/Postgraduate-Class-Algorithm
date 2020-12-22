int// assignment 3-1

/*

算法思想：运用DFS深度优先搜索的思想加上回溯剪枝
        （1） 当n个部件都已经选出时，保存其中重量不超标且重量最小的结果
        （2） 当仍在选部件时，从m个供应商中依次选择部件
                剪枝：算上某个供应商的部件，重量超标时就将这一支剪掉不再向下进行


输入样例：
3 3 7
1 2 3
3 2 1
2 3 2
1 2 3
5 4 2
2 1 2
样例输出：
1 3 1
4
*/

const int maxn = 110;
int n, m, cost;
int w[maxn][maxn], c[maxn][maxn];
vector<int> temp;
vector<int> list;
//vector<vector<int> > t;       // 用于保存所有小于cost的结果

void dfs(int i, int now_cost, int now_weight, int &min_weight) {
    if (i > n)
    {
        // 当超过了界限时，跳出
        // 当正好或小于界限时，若此结果重量小于最小重量，就保留结果
        if (now_cost <= cost && now_weight < min_weight) {
            min_weight = now_weight;
            list = temp;
            //t.push_back(temp);
        }
        return;
    }
    // 第i个原件，可从m个供应商中选取
    for (int j = 1; j <= m; j++)
    {   
        // 当算上这个供应商的部件就超过了界限时，这一步就剪掉
        if (now_cost + c[i][j] <= cost) {
            // 选与不选, 但是m个供应商中必定会选一个
            temp.push_back(j);
            // 选，就进入下一轮选下一个部件
            dfs(i + 1, now_cost + c[i][j], now_weight + w[i][j], min_weight);
            temp.pop_back();
            // 不选，继续在剩余的供应商中选取部件
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &cost);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &w[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &c[i][j]);
    // dfs入口， 从第一个部件开始选，初始重量是0
    int min_weight = INT_MAX - 1;
    dfs(1, 0, 0, min_weight);

    printf("Result:\n");
    printf("%d", list[0]);
    for (int i = 1; i < list.size(); i++) {
        printf(" %d", list[i]);
    }
    printf("\n%d", min_weight);
    return 0;
}