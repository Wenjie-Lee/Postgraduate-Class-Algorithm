#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 101
#define max(x,y) ((x)>(y)?(x):(y))
int n;
int a[MAXN];
long solve()
{
    sort(a,a+n);
    long ans=max(a[n-1]*a[0]*a[1],a[n-1]*a[n-2]*a[n-3]);
	return ans;
}
int main()
{
	scanf("%d",&n);
    for (int i=0; i<n; i++)
        scanf("%d",&a[i]);
	printf("%ld\n",solve());
	return 0;
}
