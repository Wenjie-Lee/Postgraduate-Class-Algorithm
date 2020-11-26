// assignment 4-2

/*
区间覆盖问题

算法思想：在m条线段范围内，优先用长为1的覆盖最孤立的区间，之后用一条长线段覆盖其他

实验样例1：
5 3
1 3 8 5 11
样例输出1：
7
*/
const int maxn = 100;
int n, m, a[maxn], b[maxn], length = 0;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = n - 1; i >= 1; i--)
		b[i - 1] = a[i] - a[i - 1];
	sort(b, b + n - 1);
	// b 长度 n-1
	for (int i = n - 2; i >= 0; i--)
	{
		if (m > 1) {
			length++;
			m--;
		}
		else if (m == 1)
			length += b[i];
	}
	length += 1;	// 上面求的是间距，这里还要加上开头一个区间长度，+1
	printf("%d", length);
	return 0;
}