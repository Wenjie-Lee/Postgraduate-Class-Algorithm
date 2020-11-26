/*
给定一个正整数组，给定一个数k，要求删掉k个数后剩余数组是最大的

8 3
79823657
4 1
9152
5 2
92131
*/
// 解法1：自己的解法
const int maxn = 110;
char str[maxn];
bool erase[maxn];
int n, k;
map<int, int> mp;

int char2int(char c) {
	return c - '0';
}

int main() {
	scanf("%d %d\n", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &str[i]);
		mp[char2int(str[i])]++;
	}
	int max = -1, idx = -1;
	for (int i = 0; i < k + 1; i++)
	{
		if (max < char2int(str[i])) {
			max = char2int(str[i]);
			idx = i;
		}
	}
	for (int i = 0; i < idx; i++) {
		mp[char2int(str[i])]--;
		erase[i] = true;
	}
	k -= idx++;
	for (auto i : mp) {
		for (int j = idx; j < n; j++)
		{
			if (k > 0 && i.second != 0 && i.first == char2int(str[j])) {
				k--;
				mp[char2int(str[j])]--;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (!erase[i] && mp[char2int(str[i])] > 0)
			printf("%c", str[i]);
	}
	return 0;
}

// 解法2：答案

int main() {
	string N;
	int n, k, i;
	cin >> n >> k >> N;
	// 循环直到k==0；一次循环有可能不会删掉所有最小值
	while (k--) {
		int len = N.length();
		// 当前一位小于后一位时，删除掉前一位
		for (i = 0; i < len - 1; i++)
		{
			if (N[i] < N[i+1])
			{
				N.erase(N.begin() + i);
				break;
			}
		}
		// 遍历到最后，就删除掉最后一位
		if (i == len - 1)
			N.erase(N.end() - 1);
	}
	cout << N << endl;
	return 0;
}

