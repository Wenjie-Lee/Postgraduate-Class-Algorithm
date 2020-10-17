// 练习 2-5 求解一个整数数组划分为两个子数组问题
/*
将正整数序列分为A1，A2两个序列，n1,n2,S1,S2，使|n1-n2|最小，且|S1-S2|最大
注意首先满足|n1-n2|最小，然后才是|S1-S2|最大

思想:（1）对序列排序，然后从中见分开 O(nlgn)
     （2）利用快排思想，得到第n/2大的数的索引，左右两侧即为A1,A2。
        若n是偶数，则正好中分；若n是奇数，则正好取⌊O(n)⌋，左侧序列少一个数，确保|S1-S2|最大

测试样例 1
6
9 1 9 1 9 1
测试输出 1
1~6之间从第3,4位分开；
结果是：24
测试样例 2
6
6 16 26 126 36 136
测试输出 2
1~6之间从第3,4位分开；
结果是：250
测试样例 3
7
1 6 16 26 126 36 136
测试输出 3
1~6之间从第3,4位分开；
结果是：301
测试样例 4
7
1 6 16 26 126 36 136
测试输出 4
1~6之间从第3,4位分开；
结果是：301
测试样例 5
5
0 0 0 0 -1
测试输出 5
1~5之间从第2,3位分开；
结果是：1
*/
const int maxn = 110;
int n, num[maxn];

int partition(int a[], int low, int high) {
    int t = (round(1.0 * rand() / RAND_MAX * (high - low) + low));
    swap(a[t], a[low]);
    int pivot = a[low];
    while (low < high)
    {
        while (low < high && a[high] > pivot)
            high--;
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
            low++;
        a[high] = a[low];
    }
    a[low] = pivot;
    return low;
}

int binarySearch(int a[], int low, int high, int x) {
    int mid;
    while (low <= high) {
        int p = partition(a, low, high);
        if (p == x) return p;
        else if (p < x) low = p + 1;
        else high = p - 1;
    }
    return -1;
}

int sum(int a[], int low, int high) {
    int res = 0;
    for (int i = low; i <= high; i++)
        res += a[i];
    return res;
}

int main() {
    srand((unsigned)time(NULL)); // 生成随机数种子
    scanf("%d", &n);
    // 数组第一位空下来不用，方便记录索引
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    // 优先满足|n1-n2|最小，所以寻找第（n/2）小的数的索引值
    int k = binarySearch(num, 1, n, n / 2);
    int res = abs(sum(num, 1, k) - sum(num, k + 1, n));
    //int res = -1;
    /*if (n % 2 == 0) {
        res = abs(sum(num, 1, k) - sum(num, k + 1, n));
    }
    else {
        int res1 = abs(sum(num, 1, k) - sum(num, k + 1, n));
        int res2 = abs(sum(num, 1, k+1) - sum(num, k+2, n));
        res = max(res1, res2);
        if (res == res2) k = k + 1;
    }*/
    printf("1~%d之间从第%d,%d位分开；\n", n, k, k+1);
    printf("结果是：%d", res);
    return 0;
}