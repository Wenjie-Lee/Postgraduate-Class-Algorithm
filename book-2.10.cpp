#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// 习题 2.10 桃子

int Peach(int n) {
    if (n == 1) return 1;
    return (Peach(n - 1) + 1) * 2;
}

int main() {
    int n = 0;
    printf("Type the number of day n: ");
    scanf("%d", &n);
    printf("\n");

    printf("The number of peach is: %d\n", Peach(n));

    return 0;
}