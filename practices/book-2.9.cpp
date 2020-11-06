#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// 附录实验一 递归于分治算法
// 1.Hanoi 问题
int n;
char a = 'A', b = 'B', c = 'C';
// 将n个盘从A全部送到C
// a原位置， b辅助，c目标位置
void Hanoi(char a, char b, char c, int n) {
    // 递归出口
    if (n < 1) return;
    Hanoi(a, c, b, n - 1);
    printf("move %d from %c to %c\n", n, a, c);
    Hanoi(b, a, c, n - 1);
}

int main() {
    printf("Type the n: ");
    scanf("%d", &n);
    printf("\n");
    Hanoi(a, b, c, n);
    printf("Movement complete!");
    return 0;
}