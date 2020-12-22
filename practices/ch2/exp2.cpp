#include "btree.cpp"						//包含二叉树的基本运算算法
bool Isomorphism(BTNode *bt1,BTNode *bt2)	//判断bt1和bt2是否同构
{
	if (bt1==NULL && bt2==NULL)
		return true;
	if ((bt1==NULL && bt2!=NULL) || (bt1!=NULL && bt2==NULL))
		return false;
	bool lsm=Isomorphism(bt1->lchild,bt2->lchild);
	bool rsm=Isomorphism(bt1->rchild,bt2->rchild);
	return lsm & rsm;
}

void main()
{
	BTNode *bt1,*bt2,*bt3;
	ElemType a[]={5,2,3,4,1,6};
	ElemType b[]={2,3,5,1,4,6};
	int n=sizeof(a)/sizeof(a[0]);
	bt1=CreateBTree(a,b,n);
	ElemType c[]={2,5,1,4,3,6};
	ElemType d[]={5,1,2,3,4,6};
	int m=sizeof(c)/sizeof(c[0]);
	bt2=CreateBTree(c,d,m);
	ElemType e[]={4,1,2,6,3,5};
	ElemType f[]={2,1,4,3,6,5};
	int k=sizeof(e)/sizeof(e[0]);
	bt3=CreateBTree(e,f,k);
	printf("实验结果:\n");
	printf("  二叉树bt1:"); DispBTree(bt1); printf("\n");
	printf("  二叉树bt2:"); DispBTree(bt2); printf("\n");
	printf("  二叉树bt3:"); DispBTree(bt3); printf("\n");
	printf("  bt1和bt2%s\n",(Isomorphism(bt1,bt2)?"同构":"不同构"));
	printf("  bt1和bt3%s\n",(Isomorphism(bt1,bt3)?"同构":"不同构"));
	printf("  销毁树bt1\n");
	DestroyBTree(bt1);
	printf("  销毁树bt2\n");
	DestroyBTree(bt2);
	printf("  销毁树bt3\n");
	DestroyBTree(bt3);
}
