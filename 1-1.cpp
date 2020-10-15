//#include <iostream>
#include <cstdio>
#include <cstring>
//#include <string>
//#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 课后练习 1 递归实现单链表逆置（无头结点）

const int maxn = 20;
int n;
struct node {
    int data;
    node *next;
} *lnode[maxn];

node* reverse(node *root) {
    node *p = root, *q = root->next;
    // 链表为空 
    if(!p) return NULL;
    // 链表只有一个结点 
    if(q == NULL) return p;
    
    root = reverse(q);
    q = root;
    while(q->next != NULL) q = q->next;
    q->next = p;
    p->next = NULL;
    return root;
}

int main() {
    // 构造单链表 
    scanf("%d", &n);
    node* root = lnode[0];
    for (int i = 0; i < n; i++) {
        lnode[i]->data = i;
        lnode[i]->next = root->next;
        root = lnode[i];
    }

    node *temp = root;
    printf("未逆置的链表:");
    while(temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
    // 逆置
    root = reverse(root);
    
    temp = root;
    printf("逆置后的链表:");
    while(temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    
    return 0;
} 