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

测试样例 1
21
输出样例 1
True f(1) = 1, f(1) = 1
False f(2) = 2, f(1) = 1
False f(3) = 3, f(11) = 2
False f(4) = 4, f(1) = 1
False f(5) = 5, f(101) = 2
False f(6) = 6, f(11) = 2
False f(7) = 7, f(111) = 3
False f(8) = 8, f(1) = 1
False f(9) = 9, f(1001) = 2
False f(10) = 1, f(101) = 2
False f(11) = 2, f(1101) = 3
False f(12) = 3, f(11) = 2
False f(13) = 4, f(1011) = 3
False f(14) = 5, f(111) = 3
False f(15) = 6, f(1111) = 4
False f(16) = 7, f(1) = 1
False f(17) = 8, f(10001) = 2
False f(18) = 9, f(1001) = 2
False f(19) = 10, f(11001) = 3
True f(20) = 2, f(101) = 2
True f(21) = 3, f(10101) = 3
The number: 3
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