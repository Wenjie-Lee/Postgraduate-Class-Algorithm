// 练习课1.1 
/*
给定一个序列长度n，和序列a[n]，删除“任意”两个相邻值，且将前两个值的和
插入两数之前的位置，直至序列为回文序列，统计操作次数。

思想：	（1）当序列长度为1时，或当判断是回文序列时，比较最小次数并跳出；
		（2）从序列给定位置开始循环删除并添加值，执行递归函数，再恢复之前的序列。

测试样例 0
2
1 1
测试输出 0
min count: 1
测试样例 1
4
1 1 1 3
测试输出 1
min count: 2
测试样例 2
5
7 3 1 2 7
测试输出 2
min count: 1
*/
int n, minCount = INT32_MAX;
vector<int> num, countList;		// num 记录输入序列，countList记录是回文序列时的操作次数
vector<vector<int> > vecList;	// vecList记录回文序列

bool IsPalindrome(vector<int> a) {
	if (a.size() == 1) return true;
	for (unsigned int i = 0; i < a.size(); i++)
		if (a[i] != a[a.size() - i - 1])
			return false;

	return true;
}

void function(vector<int> &a, int fcount) {
	if (a.size() == 1 || IsPalindrome(a)) {
		countList.push_back(fcount);
		vecList.push_back(a);
		if (fcount < minCount)
			minCount = fcount;
		return;
	}

	for (int i = 0; i < a.size() - 1; i++)
	{
		int x = a[i], y = a[i+1];
		a[i+1] = x + y;
		a.erase(a.begin() + i);
		function(a, fcount + 1);
		a[i] = y;
		a.insert(a.begin() + i, x);
	}
}

int main() {
	scanf("%d", &n);
	int t;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		num.push_back(t);
	}
	function(num, 0);
	printf("Num lists after operation: ");
	for each (int var in num)
		printf(" %d", var);
	printf("\n min count: %d\n", minCount);
	return 0;
}