// assignment 4-1

/*
求解最大乘积问题

算法思想：三个数乘法取最大值有两种可能
		（1） 三个最大正数相乘
		（2） 两个最小负数和一个最大正数相乘

输入样例1：
4
3 4 1 2
样例输出1：
24
输入样例2：
5
-1 -2 0 1 3
样例输出2：
6
输入样例3：
5
1 -2 0 1 3
样例输出3：
3
输入样例4：
6
-1 -2 -3 -4 -5 0
样例输出4：
0
*/

int main() {
	int n, res, temp;
	int max1 = INT32_MIN, max2 = INT32_MIN, max3 = INT32_MIN;	// 三个最大正数
	int min1 = INT32_MAX, min2 = INT32_MAX;						// 两个最小负数
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		// 最大的三个数
		if (temp > max1) {
			max3 = max2;
			max2 = max1;
			max1 = temp;
		}
		else if (temp > max2) {
			max3 = max2;
			max2 = temp;
		}
		else if (temp > max3)
			max3 = temp;
		// 最小的两个数
		if (temp < min1) {
			min2 = min1;
			min1 = temp;
		}
		else if (temp < min2)
			min2 = temp;
	}
	res = max(max1*max2*max3, min1*min2*max1);

	printf("%d", res);
	return 0;
}