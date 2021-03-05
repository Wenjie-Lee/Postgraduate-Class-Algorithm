// 练习1-2 求众数
/*
思想： 线性递增序列求众数，遍历序列的同时，使用map记录出现的数以及出现次数，
    再遍历map，将出现次数最大的数（可能不止一个）用vector记录下来
*/

int n, maxc = 0;
map<int, int> mp;
vector<pair<int, int> > vec;

int main() {
    scanf("%d", &n);
    int temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        // 创建关于数temp的索引
        // if( mp.exists(temp) )
        if (mp.find(temp) != mp.end())
            mp[temp]++;
        else
            mp[temp] = 1;
    }

    for (pair<int, int> p : mp) {
        if (p.second > maxc)
        {
            maxc = p.second;
            vec.clear();
            vec.push_back(p);
        }
        else if (p.second == maxc) {
            vec.push_back(p);
        }
    }

    printf("序列中的众数： \n");
    for (pair<int, int> p : vec)
        printf("%d, 出现次数：%d\n", p.first, p.second);
    printf("\n");

    return 0;
}

// 第二种方法，直接在读入数组时就处理，因为题目给定的数列是递增有序数列
int main() {
	int pre, now, cnt = 0, maxcnt = 0, maxnum = -1;
	cin >> pre;
	cnt++;
	maxnum = pre;
	while (cin >> now)
	{
		if (now == pre)
			cnt++;
		else {
			if (cnt > maxcnt) {
				maxcnt = cnt;
				maxnum = pre;
			}
			cnt = 0;
		}
		pre = now;
	}
	printf("%d %d\n", maxnum, maxcnt);

	return 0;
}

/*
 第三种方法，利用递归分治思想，
每次求出数列中间位置数字的左右相同数字边界，
更新众数后，再求左右边界外的数列的众数
*/
// 给出a[low， high]范围内的中间值的相同元素的索引边界[left, right)
void split(int a[], int low, int high, int &mid, int &left, int &right) {
	mid = (low + high) / 2;
	for (left = low; left < mid; left++)
		if (a[mid] == a[left])
			break;
	for (right = mid + 1; right <= high; right++)
		if (a[mid] != a[right])
			break;
}

void getmaxcnt(int a[], int low, int high) {
	if (low <= high)
	{
		int left, right, mid;
		split(a, low, high, mid, left, right);
		int cnt = right - left;	// 左闭右开范围
		if (cnt > maxcnt) {
			maxcnt = cnt;
			maxnum = a[mid];
		}
		getmaxcnt(a, low, left - 1);
		getmaxcnt(a, right, high);
	}
}