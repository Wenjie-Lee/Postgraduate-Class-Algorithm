#include "btree.cpp"						//包含二叉树的基本运算算法
int maxsum=0;								//全局变量：存放最大路径和
vector<int> maxpath;						//全局变量：存放最大路径
void Findmaxpath(BTNode *bt,vector<int> apath,int asum)
//求根结点到叶结点的路径和最大的路径
{	if (bt==NULL)							//空树直接返回
		return;
	apath.push_back(bt->data);				//bt结点加入apath
	asum+=bt->data;							//累计路径和
	if (bt->lchild==NULL && bt->rchild==NULL)	//bt结点为叶结点
	{	if (asum>maxsum)
		{	maxsum=asum;
			maxpath.clear();
			maxpath=apath;
		}
	}
	Findmaxpath(bt->lchild,apath,asum);		//在左子树中查找
	Findmaxpath(bt->rchild,apath,asum);		//在右子树中查找
}
void main()
{
	BTNode *bt;
	ElemType a[]={5,2,3,4,1,6};
	ElemType b[]={2,3,5,1,4,6};
	int n=sizeof(a)/sizeof(a[0]);
	bt=CreateBTree(a,b,n);
	printf("实验结果:\n");
	printf("  二叉树bt:"); DispBTree(bt); printf("\n");
	printf("  最大路径");
	vector<int> apath;
	int asum=0;
	Findmaxpath(bt,apath,asum);
	printf("  路径和: %d, 路径: ",maxsum);
	for (int i=0;i<maxpath.size();i++)
		printf("%d ",maxpath[i]);
	printf("\n");
	printf("  销毁树bt\n");
	DestroyBTree(bt);
}
