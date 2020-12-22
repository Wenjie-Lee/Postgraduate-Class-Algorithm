#include <stdio.h>
#include <string.h>
#define MAXN 20
void Delk(char a[],int k)				//在整数串a中删除k个数字
{	int i,m=strlen(a);
	if (k>=m)						//k>=m时全部删除
	{	a="";
		return;
	}
	while (k>0)					//在a中删除k位
	{	for (i=0;i<m-1 && a[i]<=a[i+1];i++);	//找递增区间
		printf("  删除a[i]=%c\n",a[i]);
		strcpy(a+i,a+i+1);			//删除a[i]
		k--;
		m--;
	}
	while (m>1 && a[0]=='0')			//删除前导0
		strcpy(a,a+1);
}
void longtostr(long d,char a[])			//将d的各位放入a数组中
{	int i,n=0;
	char tmp;
	while (d>0)
	{	a[n++]='0'+d%10;
		d/=10;
	}
	a[n]='\0';
	for (i=0;i<n/2;i++)				//逆置,使a[0]存放d的个位数字
	{	tmp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=tmp;
	}
}
long strtolong(char a[])				//将a串转换为长整数
{	int i,m=strlen(a);
	long d=0;
	for (i=0;i<m;i++)
		d=d*10+(a[i]-'0');
	return d;
}
int main()
{	char a[MAXN];
	long d=5004321;
	int k=3;
	longtostr(d,a);
	printf("删除前:%ld\n",d);			//输出5004321
	Delk(a,k);
	d=strtolong(a);
	printf("删除%d个数字后:%ld\n",k,d);	//输出：21
	return 0;
}
