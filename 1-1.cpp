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
typedef struct node {
	int data;
	struct node *next;
} lnode;

void createList(lnode *&root, int a[], int n) {
	lnode *p, *r;
	root = (lnode *)malloc(sizeof(lnode));
	root->data = a[0];
	r = root;
	for (int i = 1; i < n; i++)
	{
		p = (lnode *)malloc(sizeof(lnode));
		p->data = a[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

void printList(lnode *root) {
	lnode *r = root;
	while (r != NULL)
	{
		printf(" %d", r->data);
		r = r->next;
	}
	printf("\n");
}

node* reverse(node *root) {
	node *p = root, *q = root->next;
	// 链表为空 
	if (!p) return NULL;
	// 链表只有一个结点 
	if (!q) return p;

	p = reverse(q);
	//     while(q->next != NULL) q = q->next;
	//     q->next = p;
	root->next->next = root;	// 将p结点链接到q结点后面
	root->next = NULL;
	return p;
}

int main() {
	// 构造单链表 
	int num[6] = { 1,2,3,4,5,6 }, n = 6;
	node *root;
	createList(root, num, n);

	printf("未逆置的链表:");
	printList(root);
	// 逆置
	root = reverse(root);

	printf("逆置后的链表:");
	printList(root);

	return 0;
}