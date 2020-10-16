#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// 练习课1.1 
/*
    给定一个序列长度n，和序列a[n]，不断删除前两个值，且将前两个值的和
    插入两数之前的位置，直至序列为回文序列，统计操作次数。

    测试样例 0
    2
    1 1
    测试样例 1
    4
    1 1 1 3
    测试样例 2
    5
    1 3 4 4 8
*/
int n, res = 0;
vector<int> num;

bool IsPalindrome(vector<int> a) {
    if (a.size() == 1) return true;
    for (unsigned int i = 0; i < a.size(); i++)
        if (a[i] != a[a.size() - i - 1])
            return false;

    return true;
}

int main() {
    scanf("%d", &n);
    int t;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        num.push_back(t);
    }
    // 合并前两个值到后一个，删除前一个
    while (!IsPalindrome(num)) {
        res++;
        num[1] = num[0] + num[1];
        num.erase(num.begin());
    }

    printf("Num lists after operation: ");
    for each (int var in num)
    {
        printf(" %d", var);
    }
    printf("\n count: %d\n", res);
    return 0;
}