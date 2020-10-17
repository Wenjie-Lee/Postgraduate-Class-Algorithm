// 练习 2-3 分治法求序列逆序对个数
/*
思想： 考虑递归归并排序,归并排序就是恢复逆序对的过程。
    类似归并排序过程，先统计左侧逆序对数量，再统计右侧，最后统计整体。

测试样例 1
5 
3 1 4 5 2
测试输出 1
逆序对的个数是： 4
<3,1>, <5,2>, <3,2>, <4,2>
测试样例 2
8
1 2 3 4 5 6 7 0
测试输出 2
逆序对的个数是： 7
<7,0>, <5,0>, <6,0>, <1,0>, <2,0>
<3,0>, <4,0>
测试样例 3
8
2 3 5 8 1 4 5 7
测试输出 3
<2,1>, <3,1>, <5,1>, <8,1>, <5,4>
<8,4>, <8,5>, <8,7>
*/

const int maxn = 1000;
int n, num[maxn];
vector<pair<int, int> > vec;    // 用来记录逆序对
int merge(int a[], int l1, int h1, int l2, int h2) {
    int i = l1, j = l2, res = 0;
    int temp[maxn], k = 0;
    while (i <= h1 && j <= h2) {
        // 若左侧i数大于右侧j数，则i~h1都大于j
        if (a[i] > a[j]) {
            res += h1 - i + 1;
            for (int x = i; x <= h1; x++)
                vec.push_back(make_pair(a[x], a[j]));
            temp[k++] = a[j++];
        }
        // 左侧i数小于等于右侧j数，则左侧顺延一位
        else temp[k++] = a[i++];
    }
    while (i <= h1) temp[k++] = a[i++];
    while (j <= h2) temp[k++] = a[j++];
    for (int i = 0; i < k; ++i) {
        a[l1 + i] = temp[i];
    }
    return res;
}

int mergeSort(int a[], int low, int high) {
    int res = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        int left = mergeSort(a, low, mid);
        int right = mergeSort(a, mid + 1, high);
        res += left + right + merge(a, low, mid, mid+1, high);
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    int res = mergeSort(num, 0, n - 1);
    printf("逆序对的个数是： %d\n", res);
    int idx = 0;
    for (unsigned int i = 0; i < vec.size(); i++) {
        printf("<%d,%d>", vec[i].first, vec[i].second);
        idx++;
        if (idx >= 5 || i == vec.size() - 1) {
            printf("\n");
            idx = 0;
        }
        else
            printf(", ");
    }
    printf("排序后的序列：\n");
    for (int i = 0; i < n; i++)
        printf("%d", num[i]);
    return 0;
}