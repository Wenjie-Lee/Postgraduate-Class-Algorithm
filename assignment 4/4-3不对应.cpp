#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 201
#define min(x,y) ((x)<(y)?(x):(y))
//问题表示
int n;						//课程门数
struct NodeType
{	int a;					//课程i的平时成绩
	int b;					//课程i多拿一分要花的复习时间
	bool operator<(const NodeType &s)
	{					//用于按单位复习时间递增排序
		return b<s.b;
	}
};
NodeType A[MAXN];
double avg;					//小v要达到的平均成绩
int r;						//课程满分
//求解结果表示
int effort=0;					//小v需要的复习时间
void solve()					//求解奖学金问题
{	int Sums=(int)n*avg;				//小v达到条件的总分
	int sum=0;				//小v的现有课程的总分
	for (int i=0;i<n;i++)
		sum+=A[i].a;
	sort(A,A+n);				//按单位复习时间递增排序
	for (int j=0;j<n;j++)
	{	if (sum>=Sums)			//已经达到要求
			break;
		sum+=min(Sums-sum,r-A[j].a);		//累计课程i达到要求的分数
		effort+=A[j].b*min(Sums-sum,r-A[j].a);	//累计课程i达到要求的复习时间
	}
}
int main()
{
	while (true)
	{
		scanf("%d",&n);
		if (n==0) break;
		for (int i=0;i<n;i++)
			scanf("%d%d",&A[i].a,&A[i].b);
		scanf("%d%lf",&r,&avg);
		solve();
		printf("%d\n",effort);
	}
   	return 0;
}
