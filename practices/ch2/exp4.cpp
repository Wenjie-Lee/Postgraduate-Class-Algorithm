#include "BTree1.cpp"			//���������������㷨�����ֵΪchar
void Trans(BTNode *bt,int l)	//���bt�ȼ۵���׺���ʽ
{
   if (bt==NULL) return;
   else if (bt->lchild==NULL && bt->rchild==NULL) //Ҷ���
      printf("%c",bt->data);
   else
   {  if (l>1) printf("(");  		//���ӱ��ʽ��һ������
      Trans(bt->lchild,l+1);		//����������
      printf("%c",bt->data);		//���������
      Trans(bt->rchild,l+1);		//����������
      if (l>1) printf(")");		//���ӱ��ʽ��һ������
   }
}
void BTreeToExp(BTNode *bt)		//���������bt�ȼ۵���׺���ʽ
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
	printf("ʵ����:\n");
	printf("  ������bt1:"); DispBTree(bt1); printf("\n");
	printf("  bt1����׺���ʽ:");BTreeToExp(bt1);
	printf("  ������bt2:"); DispBTree(bt2); printf("\n");
	printf("  bt2����׺���ʽ:");BTreeToExp(bt2);
	printf("  ������bt1\n");
	DestroyBTree(bt1);
	printf("  ������bt2\n");
	DestroyBTree(bt2);
}
