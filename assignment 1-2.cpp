#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// 练习课1.2 
/*
    求 x <= n，f(x) == g(x) 的情况的个数；
    f(x) = x的十进制表示的每一位的和
    g(x) = x的二进制表示的每一位的和
*/
const int maxn = 100000;
int n, num = 0;

int add(int x) {
    int res = 0;
    while (x) {
        res += x - x / 10 * 10;
        x /= 10;
    }
    return res;
}

int ten2Binary(int x) {
    int res = 0;
    while (x)
    {
        res = res * 10 + x % 2;
        x /= 2;
    }
    return res;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int a = add(i), b = ten2Binary(i), c = add(ten2Binary(i));
        if (a == c)
        {
            num++;
            printf("True ");
        }
        else {
            printf("False ");
        }
        printf("f(%d) = %d", i, a);
        printf(", f(%d) = %d\n", b, c);
    }
    printf("The number: %d", num);

    return 0;
}