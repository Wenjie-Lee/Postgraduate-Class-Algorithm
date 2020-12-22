#include "LinkList.cpp"			//包含单链表的基本运算算法
LinkNode *Reverse(LinkNode *L)	//逆置不带头结点的单链表L
{	LinkNode *p;
	if (L==NULL || L->next==NULL)
		return L;
	p=Reverse(L->next);
	L->next->next=L; 			//将L结点链接到L->next结点后面
	L->next=NULL;				//将L结点作为整个逆置后的尾结点
	return p;
}
void main()						//调试主函数
{
	ElemType a[]={1,2,3,4,5,6};
	int n=sizeof(a)/sizeof(a[0]);
	LinkNode *L;
	CreateList(L,a,n);
	printf("实验结果:\n");
	printf("  逆置前L: "); DispList(L);
	printf("  执行L=Reverse(L)\n");
	L=Reverse(L);
	printf("  逆置后L: "); DispList(L);
	printf("  销毁L\n");
	DestroyList(L);				//销毁单链表
}

