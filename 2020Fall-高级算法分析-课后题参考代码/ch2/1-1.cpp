#include <stdio.h>
//问题表示
int n;
int solve(int n,int r)	//求十进制数n转换为r进制数和各位和
{
	int res=0;
	if (n<r) return n;
	return n%r+solve(n/r,r);
}
 
int main()
{
	scanf("%d",&n);
	int ans=0;
	for (int i=1; i<=n; i++)
		if(solve(i,10)==solve(i, 2))
			ans++;
	printf("%d\n",ans);
	return 0;
}
