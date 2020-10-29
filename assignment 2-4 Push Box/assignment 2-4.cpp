// 练习 2-4 求解推箱子问题
/*

数据：
4 4
....
..*@
....
.X..
6 6
...#..
......
#*##..
..##.#
..X...
.@#...
0
答案：
3
11
*/
// 上 下 左 右
const vector<pair<int, int>> dir = { { 0,-1 },{ 0,1 },{ -1,0 },{ 1,0 } };
int n, m;
vector<string> path;
bool visit[10][10][10][10];
struct node {
    int x, y, bx, by, step;
    node(int x, int y, int bx, int by, int step) :
        x(x), y(y), bx(bx), by(by), step(step) {};
};

bool valid(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (path[x][y] == '#') return false;
    return true;
}

int bfs(int x_begin, int y_begin, int x_end, int y_end) {
    queue<node> q;
    q.push(node(x_begin, y_begin, x_end, y_end, 0));
    visit[x_begin][y_begin][x_end][y_end] = 1;
    while (!q.empty())
    {
        node d = q.front();
        q.pop();
        int bx = d.bx, by = d.by, step = d.step;
        // 四个方向尝试
        for (int i = 0; i < 4; i++)
        {
            int x = d.x + dir[i].first;
            int y = d.y + dir[i].second;
            // 假设箱子被从这个方向推一下后的位置
            int next_x = bx + dir[i].first;
            int next_y = by + dir[i].second;
            if (!valid(x, y)) continue;
            // 记录小人走的路径
            // 先走到箱子旁边
            if ((x != bx || y != by) && !visit[x][y][bx][by])
            {
                visit[x][y][bx][by] = 1;
                q.push(node(x, y, bx, by, step + 1));
            }
            // 当小人和箱子坐标相同时，说明要推一下箱子了，就按之前模拟的方向更新箱子坐标
            else if (x == bx && y == by && valid(next_x, next_y) && !visit[x][y][next_x][next_y]) {
                visit[x][y][next_x][next_y] = 1;
                if (path[next_x][next_y] == '@')
                    return step + 1;
                q.push(node(x, y, next_x, next_y, step + 1));
            }
        }
    }
    return -1;
}
// X 玩家， * 箱子， # 障碍， @ 目的地
int main() {
    do
    {
        cin >> n;
        if (n == 0) break;
        cin >> m;
        memset(visit, 0, sizeof(visit));
        path = vector<string>(n, string(""));
        for (int i = 0; i < n; i++)
            cin >> path[i];
        // 找到箱子和小人的位置
        int x_begin, y_begin, x_end, y_end;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (path[i][j] == 'X')      // 找到小人
                    x_begin = i, y_begin = j;
                else if (path[i][j] == '*')
                    x_end = i, y_end = j;   // 找到箱子
            }
        }
        cout << bfs(x_begin, y_begin, x_end, y_end) << endl;
    } while (true);

    return 0;
}