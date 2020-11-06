#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// 习题 2.12 n个数的全部排列
const int maxn = 20;
int n, num[maxn], cou = 1;

void Arrangement(int t[],int n, int index, int &count) {
    // 出口
    if (index == n-1) {
        for (int i = 0; i < n; i++)
            printf("%d", t[i]);
        count += 1;
        if (count == cou) count = 0;
        else printf(", ");
        return;
    }

    for (int i = index; i < n; i++)
    {
        swap(t[i], t[index]);
        Arrangement(t, n, index+1, count);
        swap(t[i], t[index]);
        
        if (index == 0) printf("\n");
    }
}

int main() {
    printf("Type number n: ");
    scanf("%d", &n);
    printf("\n");
    for (int i = 0; i < n; i++) num[i] = i+1;
    for (int i = 0; i < n - 1; i++)
        cou *= num[i];
    int a = 0;
    Arrangement(num, n, 0, a);

    return 0;
}