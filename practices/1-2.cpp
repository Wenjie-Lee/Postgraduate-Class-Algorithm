//#include <iostream>
#include <cstdio>
#include <cstring>
//#include <string>
//#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 课后练习 2 判断二叉树同构
const int maxn = 10;
int n1, n2, rt1=0, rt2=0;
int check[maxn];

struct treeNode {
    char d;
    int l, r;
}t1[maxn], t2[maxn];

bool Isomorphic(int n1, int n2) {
    // 至少一个是空情况下，若全是空，则为同构；若只有一个空，非同构 
    if (n1 == -1 || n2 == -1)
        return (n1 == -1) && (n2 == -1);
    // 都不空时，若数据不对，则不同构 
    if (t1[n1].d != t2[n2].d)
        return false;

    // 二叉树根节点交换或者不交换后内容一致，可称为同构 
    if (Isomorphic(t1[n1].l, t2[n2].l) && Isomorphic(t1[n1].r, t2[n2].r)) return true;
    if (Isomorphic(t1[n1].l, t2[n2].r) && Isomorphic(t1[n1].r, t2[n2].l)) return true;
    return false;
}

int main() {
    scanf("%d\n", &n1);
    char l, r;
    // 获取第一个二叉树的输入，并获得根节点的索引值
    for (int i = 0; i < n1; i++) check[i] = 0;
    for (int i = 0; i < n1; i++)
    {
        scanf("%c %c %c\n", &t1[i].d, &l, &r);
        if (l != '-') {
            t1[i].l = l - '0';
            // 此点有根，不会是根节点
            check[t1[i].l] = 1;
        }
        else t1[i].l = -1;
        if (r != '-') {
            t1[i].r = r - '0';
            check[t1[i].r] = 1;
        }
        else t1[i].r = -1;
    }
    for (int i = 0; i < n1; i++) {
        if (!check[i]) {
            rt1 = i;
            break;
        }
    }
    // 空树，直接设为-1 
    if (n1 < 1) rt1 = -1;
        
    // 获取第二个二叉树的输入，并获得根节点的索引值
    scanf("%d\n", &n2); 
    for (int i = 0; i < n2; i++) check[i] = 0;
    for (int i = 0; i < n2; i++)
    {
        scanf("%c %c %c\n", &t2[i].d, &l, &r);
        if (l != '-') {
            t2[i].l = l - '0';
            // 此点有根，不会是根节点
            check[t2[i].l] = 1;
        }
        else t2[i].l = -1;
        if (r != '-') {
            t2[i].r = r - '0';
            check[t2[i].r] = 1;
        }
        else t2[i].r = -1;
    }
    for (int i = 0; i < n2; i++) {
        if (!check[i]) {
            rt2 = i;
            break;
        }
    }
    // 空树，直接设为-1 
    if (n2 < 1) rt2 = -1;

    if (Isomorphic(rt1, rt2)) printf("Yes");
    else printf("No");

    return 0;
}