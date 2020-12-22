//二叉树的基本运算算法
#include <malloc.h>
#include <stack>
#include <vector>
#include <string>
using namespace std;
typedef int ElemType;
typedef struct node 
{	ElemType data;				//数据元素
	struct node *lchild;		//指向左孩子结点
	struct node *rchild;		//指向右孩子结点
} BTNode;						//二叉链结点类型

BTNode *CreateBTree(ElemType a[],ElemType b[],int n)	//对应例2.8的算法
//由先序序列a[0..n-1]和中序序列b[0..n-1]建立二叉链
{
	int k;
	if (n<=0) return NULL;
	ElemType root=a[0];			//根结点值
	BTNode *bt=(BTNode *)malloc(sizeof(BTNode));
	bt->data=root;
	for (k=0;k<n;k++)			//在b中查找b[k]=root的根结点
		if (b[k]==root)
			break;
	bt->lchild=CreateBTree(a+1,b,k);			//递归创建左子树
	bt->rchild=CreateBTree(a+k+1,b+k+1,n-k-1);	//递归创建右子树
	return bt;
}
void DispBTree(BTNode *bt)				//采用括号表示输出二叉链bt
{
	if (bt!=NULL)
	{	printf("%d",bt->data);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	printf("(");						//有孩子结点时才输出(
			DispBTree(bt->lchild);				//递归处理左子树
			if (bt->rchild!=NULL) printf(",");	//有右孩子结点时才输出,
			DispBTree(bt->rchild);				//递归处理右子树
			printf(")");						//有孩子结点时才输出)
		}
	}
}
void DestroyBTree(BTNode *&bt)		//对应例2.9的算法
//释放以bt为根结点的二叉树
{	if (bt!=NULL)
	{	DestroyBTree(bt->lchild);
		DestroyBTree(bt->rchild);
		free(bt);
	}
}
