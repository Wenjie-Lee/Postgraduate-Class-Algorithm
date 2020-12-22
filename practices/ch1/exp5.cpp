#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> > A;	//小根堆
priority_queue<int> B;								//大根堆
void Insert(int x)				//插入整数x
{
	if (A.size()==0)			//A为空，直接插入x
		A.push(x);
	else if (x>A.top())			//x大于A堆顶元素,插入到A中
	{
		A.push(x);
		if (A.size()>B.size())	//若A中元素多于B，将堆顶元素移动到B中
		{
			int e=A.top();
			A.pop();
			B.push(e);
		}
	}
	else						//x不大于A堆顶元素,插入到B中
	{
		B.push(x);
		if (B.size()>A.size())	//若B中元素多于A，将堆顶元素移动到A中
		{
			int e=B.top();
			B.pop();
			A.push(e);
		}
	}
		
}
int Middle()		//求中位数
{
	if (A.size()>B.size())
		return A.top();
	else
		return B.top();
}
void main()
{
	printf("求解结果\n");
	printf("  插入2,6,1\n");
	Insert(2);
	Insert(6);
	Insert(1);
	printf("  中位数=%d\n",Middle());
	printf("  插入3,4\n");
	Insert(3);
	Insert(4);
	printf("  中位数=%d\n",Middle());
	printf("  插入5,7\n");
	Insert(5);
	Insert(7);
	printf("  中位数=%d\n",Middle());
}






