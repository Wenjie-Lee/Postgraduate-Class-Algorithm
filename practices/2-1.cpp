// 练习2-1 找假币

/*
思想： 
    （1） 每次将硬币序列分为两份，分别计算各份的均质量，
    （2） 选均质量小的那一份继续第一步，直到所分的份中仅剩一枚硬币

测试样例 1
5
2 2 1 2 2
测试输出 1
假币的索引值： 2
测试样例 2
10
1 5 5 5 5 5 5 5 5 5
测试输出 2
假币的索引值： 0
*/

const int maxn = 100;
int n, idx = -1;
double coin[maxn];

double meanWeight(double a[], int low, int high) {
    double weight = 0;
    if (low <= high) {
        for (int i = low; i <= high; i++)
            weight += a[i];
    }
    return weight / (high - low + 1);
}

int binarySearch(double a[], int low, int high) {
    int mid, i = low, j = high;
    while (i < j)
    {
        mid = i + (j - i) / 2;
        // 若左边均质量高于右边，则假币在右边
        if (meanWeight(a, i, mid) > meanWeight(a, mid + 1, j))
            i = mid + 1;
        // 没有等于情况
        // 若小于，则假币在左边
        else
            j = mid;
    }
    return i;
}

int main() {
    // 输入硬币数量，每个硬币的重量，其中有一个重量比其他的轻
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &coin[i]);

    idx = binarySearch(coin, 0, n - 1);

    printf("假币的索引值: %d", idx);
    return 0;
}