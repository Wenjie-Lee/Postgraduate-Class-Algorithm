/* 
ab-cd+e=1 没有解
ab-cd-e=1 有解
3*4-2*5-1=1
3*4-5*2-1=1
4*3-2*5-1=1
4*3-5*2-1=1
*/
int num[5], n = 5;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void dfs(int i) {
	if (i == n)
		if (num[0] * num[1] - num[2] * num[3] - num[4] == 1)
			printf("%d*%d-%d*%d-%d=1\n", num[0], num[1], num[2], num[3], num[4]);
	for (int j = i; j < n; j++)
	{
		swap(num[i], num[j]);
		dfs(i + 1);
		swap(num[i], num[j]);
	}
}

int main() {
	// 初始化
	for (int i = 0; i < 5; i++)
		num[i] = i + 1;
	dfs(0);
	return 0;
}