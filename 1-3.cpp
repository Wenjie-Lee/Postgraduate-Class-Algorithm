#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// 课后练习 3 求二叉树中最大和路径 递归式

// DFS问题

// Input: 
//   value: 5 | 2 | 3 | 4 | 1 | 6 
//   index: 0 | 1 | 2 | 3 | 4 | 5
// 6            version2:   6 
// 5 1 3                    5 1 3
// 2 - 2                    2 - 2
// 3 - -                    3 - -
// 4 4 5                    4 4 5
// 1 - -                    1 - -
// 6 - -                    0 - -  这个会有两天和值相同的路径

const int maxn = 20;
int n, check[maxn], root;
struct node {
    int data;
    node *l, *r;
} bt[maxn];

int sumindex = 0, maxsum = -1;
int sum[maxn]{0};
vector<int> temp;
vector< vector<int>> path;

void DFSTrasverse(node *root, int level) {
    // 每过一个点，就计算新的和，添加点到当前路径
    sum[level] = sum[level-1] + root->data;
    temp.push_back(root->data);
    // 到达了一条路径的尽头
    if (!root->l && !root->r) {
        if (sum[level] > maxsum) {
            maxsum = sum[level];
            path.clear();
            path.push_back(temp);
        }
        // 有多条路径可以达到这个sum值
        else if (sum[level] == maxsum) {
            path.push_back(temp);
        }
    }
    // 没有达到尽头
    else {
        if(root->l) 
            DFSTrasverse(root->l, level+1);
        if (root->r)
            DFSTrasverse(root->r, level + 1);
    }
    // 最后重置变量回到初始层
    temp.pop_back();
}

int main() {
    char l, r;
    scanf("%d\n", &n);
    // 获取第一个二叉树的输入，并获得根节点的索引值
    for (int i = 0; i < n; i++) check[i] = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %c %c\n", &bt[i].data, &l, &r);
        if (l != '-') {
            bt[i].l = &bt[l - '0'];
            // 此点有根，不会是根节点
            check[l - '0'] = 1;
        }
        else bt[i].l = NULL;
        if (r != '-') {
            bt[i].r = &bt[r - '0'];
            check[r - '0'] = 1;
        }
        else bt[i].r = NULL;
    }
    for (int i = 0; i < n; i++) {
        if (!check[i]) {
            root = i;
            break;
        }
    }

    DFSTrasverse(&bt[root], 1);

    printf("Max of sum is: %d\n", maxsum);
    printf("path (sometimes more than one path): \n");
    for (int x = 0; x < path.size(); x++)
    {
        printf("%d: %d", x+1, path[x][0]);
        for (int i = 1; i < path[x].size(); i++)
        {
            printf("->%d", path[x][i]);
        }
        printf(".\n");
    }

    return 0;
}