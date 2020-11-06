// 练习3-1 求解 floor(sqrt(n)) 问题
/*
思想： 先求出sqrt(n)近似值，
    再从1到sqrt(n)以步长1遍历求最大的值x，x满足x<=sqrt(n)
### 感觉有更好的方法
*/
const double eps = 1e-5;
int n;
double m;

double f(double x) {
    return x * x;
}

double binary_search(double k) {
    double mid, i = 1, j = k;
    if (k == 1) return 1;
    while (j - i > eps) {
        mid = i + (j - i) / 2;
        if (f(mid) > k) j = mid;
        else i = mid;
    }
    return mid;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        // 1 <= sqrt(i) < i
        m = binary_search(i);
        double max_m = 1;
        for (double j = 1; j <= m; j++) {
            if (j <= m) {
                max_m = j;
            }
        }
            
        printf("floor(sqrt(%d)) = %.2f\n", i, max_m);
    }
    return 0;
}
