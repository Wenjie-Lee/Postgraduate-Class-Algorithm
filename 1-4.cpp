#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


// 课后练习 4 输出表达式树的中缀表达式
// Input 1:
// 8
//* 1 4
//+ 2 3
//a - -
//b - -
//+5 6
//c - -
//- - 7
//d - -

// Input 2:
//8
//+ 1 4
//* 2 3
//a - -
//b - -
//--5
//- 6 7
//c - -

const int maxn = 20;
int n, check[maxn];

struct node {
    char data;
    node *l, *r;
} bt[maxn];

void InOrder(node* root, int level) {
    if (!root->l && !root->r) {
        printf("%c", root->data);
        return;
    }
    // 中序表达式
    if (level > 0) printf("(");
    if (root->l) InOrder(root->l, level+1);
    printf("%c", root->data);
    if (root->r) InOrder(root->r, level+1);
    if (level > 0) printf(")");
}

int main() {
    char l, r;
    scanf("%d\n", &n);
    // 获取第一个二叉树的输入，并获得根节点的索引值
    for (int i = 0; i < n; i++) check[i] = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%c %c %c\n", &bt[i].data, &l, &r);
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
    int root = 0;
    for (int i = 0; i < n; i++) {
        if (!check[i]) {
            root = i;
            break;
        }
    }

    InOrder(&bt[root], 0);

    return 0;
}