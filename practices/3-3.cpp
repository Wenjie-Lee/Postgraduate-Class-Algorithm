// 练习3-3 求解环绕区域问题
/*
思想： 按图的连通问题做，DFS,BFS
输入样例1
4 4
XXXX
XOOX
XXOX
XOXX
输出样例1
DFS输出区域：
XXXX
XXXX
XXXX
XOXX
输入样例2
5 5
XXXXX
XOOOX
XXOXX
XOXXO
XOOXX
输出样例2
DFS:
XXXXX
XXXXX
XXXXX
XOXXO
XOOXX
BFS:
XXXXX
XXXXX
XXXXX
XOXXO
XOOXX
*/
const int maxn = 5;
int H, W;
char zone[maxn][maxn], zone2[maxn][maxn], x='X', o='O';
bool visit[maxn][maxn], convert[maxn][maxn];
bool visit2[maxn][maxn];

bool DFS(int h, int w) {
    visit[h][w] = true;
    // 若该点在边缘，则返回false, 这条是防止输入出错
    if (h < 0 || h > H - 1 || w < 0 || w > W - 1) {
        return false;
    }
    bool circled = true;
    // 上下左右临近点有的超出界限了，即这个点在边缘
    if (h - 1 < 0 || h + 1 >= H || w - 1 < 0 || w + 1 >= W) {
        circled = false;
    }
    // up
    if (zone[h - 1][w] == o && !visit[h - 1][w]) {
        circled = DFS(h - 1, w);
    }
    // left
    if (zone[h][w - 1] == o && !visit[h][w - 1]) {
        circled = DFS(h, w - 1);
    }
    // down
    if (zone[h + 1][w] == o && !visit[h + 1][w]) {
        circled = DFS(h + 1, w);
    }
    // right
    if (zone[h][w + 1] == o && !visit[h][w + 1]) {
        circled = DFS(h, w + 1);
    }
    // 被包围时，标记为要转换的
    if (circled) convert[h][w] = true;
    return circled;
}

void BFS(int h, int w, vector<pair<int, int> > &vec) {
    queue<pair<int, int> > q;
    // 若该点在边缘，则返回false, 这条是防止输入出错
    if (h < 0 || h > H - 1 || w < 0 || w > W - 1) {
        return;
    }
    bool circled = true;
    q.push(make_pair(h, w));
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        h = p.first, w = p.second;
        vec.push_back(p);
        visit2[h][w] = true;
        q.pop();
        // 上下左右临近点有的超出界限了，即这个点在边缘
        if (h - 1 < 0 || h + 1 >= H || w - 1 < 0 || w + 1 >= W) {
            circled = false;
        }
        else {
            // up
            if (zone2[h - 1][w] == o && !visit2[h - 1][w]) {
                q.push(make_pair(h - 1, w));
            }
            // left
            if (zone2[h][w - 1] == o && !visit2[h][w - 1]) {
                q.push(make_pair(h, w - 1));
            }
            // down
            if (zone2[h + 1][w] == o && !visit2[h + 1][w]) {
                q.push(make_pair(h + 1, w));
            }
            // right
            if (zone2[h][w + 1] == o && !visit2[h][w + 1]) {
                q.push(make_pair(h, w + 1));
            }
        }
    }
    // 若没有被包围，就丢弃掉序列
    if (!circled) vec.clear();
}

int main() {
    scanf("%d%d\n", &H, &W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%c", &zone[i][j]);
            zone2[i][j] = zone[i][j];
        }
        scanf("\n");
    }
    // DFS
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (zone[i][j] == o && !visit[i][j])
                DFS(i, j);
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (zone[i][j] == o && convert[i][j])
                zone[i][j] = x;
        }
    }
    printf("DFS:\n");
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            printf("%c", zone[i][j]);
        printf("\n");
    }
    // BFS
    vector<pair<int, int> > vec;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (zone2[i][j] == o && !visit2[i][j]) {
                BFS(i, j, vec);
                for (auto v : vec)
                    zone2[v.first][v.second] = x;
                vec.clear();
            }   
        }
    }
    printf("BFS:\n");
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            printf("%c", zone2[i][j]);
        printf("\n");
    }
    return 0;
}