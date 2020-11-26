// assignment 4-3

/*
算法思想：每天只能做一个作业，根据贪心算法思想，
		（1） 尽量把逾期扣分多的先做
		（2） 且在不超过deadline时尽量往后拖延（即deadline那一天做扣分最多的作业）


实验样例1：
3
1 3 1
6 2 3
样例输出：
3
实验样例2：
5
1 2 2 3 3
4 2 1 100 200
样例输出：
3（第一天做4分的，第二天做200分的，第三天做100分的）
实验样例3：
4
1 2 7 7 6
4 2 1 10 50
样例输出：
0
*/

const int maxn = 100;
int n, res, max_done;	// max_done 最多能完成几个作业
bool day[maxn];			// 记录某一天是否已经被占用

struct assignment {
	int deadline, loss;
} a[maxn];
struct daily {
	int day, loss;
} d[maxn];
// daily按照loss排序后，用来对应排序前后的索引，排序前的索引还有用
int mp[maxn];

bool cmp1(assignment a, assignment b) {
	return a.loss > b.loss;
}
bool cmp2(daily a, daily b) {
	return a.loss > b.loss;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].deadline);
		max_done = max(max_done, a[i].deadline);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].loss);
	sort(a + 1, a + n + 1, cmp1);
	// 统计同一天截至的所有作业的逾期扣分和
	for (int i = 1; i <= n; i++) {
		d[a[i].deadline].loss += a[i].loss;
		d[a[i].deadline].day = a[i].deadline;
	}
	// 对应排序前后的索引
	sort(d + 1, d + max_done + 1, cmp2);
	for (int i = 0; i < n; i++)
		mp[d[i].day] = d[i].loss;
	// mp从后往前索引
	int mpidx = max_done;
	for (int i = 1; i <= n; i++)
	{
		if (max_done == 0) break;
		// 优先占用deadline天
		if (!day[a[i].deadline])
		{
			mp[a[i].deadline] -= a[i].loss;
			day[a[i].deadline] = true;
			max_done--;
		}
		// deadline天已被占用，就往前找扣分最少的一天占用
		else {
			if (a[i].deadline <= 1) continue;
			while (mpidx >= 0)
			{
				if (!day[d[mpidx].day] && d[mpidx].day < a[i].deadline && mp[d[mpidx].day] < a[i].loss)
				{
					mp[a[i].deadline] -= a[i].loss;
					day[mpidx--] = true;
					max_done--;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		res += mp[i];
	printf("%d", res);
	return 0;
}