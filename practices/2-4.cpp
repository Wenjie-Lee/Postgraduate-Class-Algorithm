// 练习 2-4 求解半数集
/*
思想： 运用递归思想
    （1）n=0, 递归出口；
     (2) n!=0, 现有数字属于半数集；
         同时i = 0 to n/2，将i加入数字前，以新数字调用递归，递归跳出后将加入的数字推出。

测试样例 1
6
测试输出 1
输出半数集set(6):
6, 16, 26, 126, 36, 136
*/
int n;
vector<vector<int> > vec;
vector<int> temp;

void generateSet(int n, vector<int> &temp, vector<vector<int> > &vec) {
    if (n == 0) return;

    vec.push_back(temp);
    for (int i = 0; i <= n / 2; i++)
    {
        temp.push_back(i);
        generateSet(i, temp, vec);
        temp.pop_back();
    }
}

int main() {
    scanf("%d", &n);
    temp.push_back(n);
    generateSet(n, temp, vec);

    printf("输出半数集set(%d): \n", n);
    for (int i = 0; i < vec.size(); i++) {
        for (int j = vec[i].size() - 1 ; j >= 0; j--)
            printf("%d", vec[i][j]);
        if (i != vec.size() - 1) printf(", ");
        else printf("\n");
    }

    return 0;
}