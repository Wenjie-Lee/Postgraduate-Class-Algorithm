// practice 6-1

/*
求解4皇后问题

解法1：把n皇后问题看作是判断n列皇后是否合法的问题，即1~n的排列问题；
        只需要美剧1~n的所有排列，查看放置方案是否合法。

解法2：BFS方法。
*/
const int maxn = 10;
int n, num = 0, pos[maxn];  // pos[] 存放已经放置的皇后的对应行号
bool hashtable[maxn];

void generatePos(int index) {
    if (index > n) {
        num++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!hashtable[i])
        {
            bool flag = true;
            // 遍历之前放的皇后，如果此列非法，就跳过
            for (int pre = 1; pre < index; pre++)
                // 第index列皇后行号为循环的i，第pre列行号为pos[pre]
                if (abs(index - pre) == abs(i - pos[pre])) {
                    flag = false;
                    break;
                }
            // 可以把第index列的皇后放在第i行
            if (flag) {
                pos[index] = i;
                hashtable[i] = true;
                generatePos(index + 1); // 生成index+1列皇后
                hashtable[i] = false;   // 递归完毕，还原第i行为未占领
            }
        }
    }
}

int main() {
    n = 4;
    generatePos(1);
    printf("cols:");
    for (int i = 1; i <= n; i++)
        printf("%d", i);
    printf("\nrows:");
    for (int i = 1; i <= n; i++)
        printf("%d", pos[i]);
    return 0;
}

int n = 4, num = 0;
struct node {
    int row;        // 结点编号，结点行号
    vector<int> cols;   // 记录已放置皇后的列
    bool operator<(const node &s) const {
        return row < s.row;
    }
};

bool valid(vector<int> cols, int col, int row) {
    int k = 0;
    // 1~row 是当前已经排过的行号，0~row-1是cols索引
    while (k < row) {
        if (col == cols[k] || abs(col - cols[k]) == abs(row - k))
            return false;
        k++;
    }
    return true;
}

void BFS() {
    node n1, n2;
    n1.row = -1;
    priority_queue<node> q;
    q.push(n1);
    while (!q.empty())
    {
        n1 = q.top();
        q.pop();
        // 
        if (n1.row == n - 1) {
            printf("cols:");
            for (int i = 0; i < n; i++)
                printf("%d", n1.cols[i]);
            printf("\nrows:");
            for (int i = 0; i < n; i++)
                printf("%d", i);
            printf("\n");
            break;
        }
        else {
            for (int col = 0; col < n; col++)
            {   // 对于一个固定的行值row，遍历所有列
                int row = n1.row + 1;
                if (valid(n1.cols, col, row))
                {
                    n2.row = row;
                    n2.cols = n1.cols;
                    n2.cols.push_back(col);
                    q.push(n2);
                }
            }
        }
    }
}

int main() {
    BFS();
    return 0;
}