/*
从给定的数组中找出出现次数最多的数

1
10
: 10
6
10 1 10 20 30 20
: 10
7
10 1 10 20 30 20 20
: 20
*/

// 解法1：没用到贪心 
// 用到map O(nlgn)
int n;
map<int, int> mp;
int main() {
    cin >> n;
    int tmp, max_time = 0, max_num = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        mp[tmp]++;
    }
    for (auto i : mp) {
        if (i.second > max_time) {
            max_num = i.first;
            max_time = i.second;
        }
    }
    cout << max_num << endl;
    return 0;
}

// 解法2
// 用到sort快排 O(nlgn)~O(n^2)
const int maxn = 1010;
int n, num[maxn];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);
    // 先设定为第一个数
    int times = 1, max_num = num[0], max_times = 1;
    for (int i = 1; i < n; i++)
    {
        // 同数字就times+1
        if (num[i - 1] == num[i]) {
            times++;
        }
        // 数字不同就判断上一次统计结果
        else {
            if (times > max_times) {
                max_times = times;
                max_num = num[i - 1];
            }
            // 这一次的数字
            times = 1;
        }
    }
    // i == n 时 num[n-1]单独判断
    if (times > max_times) {
        max_times = times;
        max_num = num[n-1];
    }
    cout << max_num << endl;
    return 0;
}