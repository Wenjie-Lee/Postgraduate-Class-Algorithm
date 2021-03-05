// practice 6-3

/*
最小重量机器设计
n个零件，都分别从m个供应商处购买，零件价格重量均不同；
求总价不超过d的最小重量机器设计方案
n m d
3 3 4
1 2 3
3 2 1
2 2 2
1 2 3
3 2 1
2 2 2
:4
1 3 1
*/
const int maxn = 10, inf = 99999999;
int n, m, d, w[maxn][maxn], c[maxn][maxn];
int num;    // 记录最优方案的个数，有可能有多个最优
struct design {
    int weight = 0, price = 0, num = 0;
    double wpern = 0;
    vector<int> supplier;
    bool operator<(const design& de) const {
        return wpern < de.wpern;
    }
} opt;
void bfs() {
    design de, de1;
    // 初始化取1号零件的1号供应商
    de.num = 1, de.weight += w[0][0], de.price += c[0][0];
    de.supplier.push_back(0);
    de.wpern = double(de.weight) / double(de.num);
    priority_queue<design> q;
    q.push(de);
    while (!q.empty())
    {
        de1 = q.top();
        q.pop();
        if (de1.num == n) {
            if (de1.weight <= opt.weight) {
                opt = de1;
                printf("solver%d:\n", ++num);
                printf("%d\n%d", opt.weight, opt.supplier[0] + 1);
                for (int i = 1; i < m; i++)
                    printf(" %d", opt.supplier[i] + 1); // 0~m-1 -> 1~m
                printf("\n");
            }
        }
        else {
            int no = de1.num;
            for (int i = 0; i < m; i++)
            {   // 遍历no号零件供应商
                // 若和 > d，则跳过
                if (de1.price + c[no][i] > d) continue;
                de1.num++;
                de1.price += c[no][i];
                de1.weight += w[no][i];
                de1.supplier.push_back(i);
                de1.wpern = double(de1.weight) / double(de1.num);
                q.push(de1);
                // 恢复原状
                de1.num--;
                de1.price -= c[no][i];
                de1.weight -= w[no][i];
                de1.supplier.pop_back();
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &c[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &w[i][j]);
    opt.num = n;
    opt.weight = inf;
    opt.price = inf;
    bfs();
    return 0;
}