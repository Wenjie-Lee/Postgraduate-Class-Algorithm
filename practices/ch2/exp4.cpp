#include "BTree1.cpp"			//二叉树基本运算算法，结点值为char
void Trans(BTNode *bt,int l)	//输出bt等价的中缀表达式
{
   if (bt==NULL) return;
   else if (bt->lchild==NULL && bt->rchild==NULL) //叶结点
      printf("%c",bt->data);
   else
   {  if (l>1) printf("(");  		//有子表达式加一层括号
      Trans(bt->lchild,l+1);		//处理左子树
      printf("%c",bt->data);		//输出操作符
      Trans(bt->rchild,l+1);		//处理右子树
      if (l>1) printf(")");		//有子表达式加一层括号
   }
}
void BTreeToExp(BTNode *bt)		//输出二叉树bt等价的中缀表达式
{
    Trans(bt,1);
	printf("\n");
}
void main()
{
	BTNode *bt1,*bt2;
	ElemType a[]="*+ab*c-d";
	ElemType b[]="a+b*c*-d";
	int n=8;
	bt1=CreateBTree(a,b,n);
	ElemType c[]="+*ab--cd";
	ElemType d[]="a*b+-c-d";
	int m=8;
	bt2=CreateBTree(c,d,m);
	printf("实验结果:\n");
	printf("  二叉树bt1:"); DispBTree(bt1); printf("\n");
	printf("  bt1的中缀表达式:");BTreeToExp(bt1);
	printf("  二叉树bt2:"); DispBTree(bt2); printf("\n");
	printf("  bt2的中缀表达式:");BTreeToExp(bt2);
	printf("  销毁树bt1\n");
	DestroyBTree(bt1);
	printf("  销毁树bt2\n");
	DestroyBTree(bt2);
}
