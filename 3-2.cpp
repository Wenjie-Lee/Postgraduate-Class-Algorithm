// 连续 3-2 兑换钱币
/*
思想：递归DFS，
    （1）当兑换完了，跳出递归；
    （2）计算当前剩余钱数能兑换的最大面值钱币，选择兑换不同的数量分别进入递归(0~x个)；
*/
const int COIN[3] = {5,2,1};
int n, list_num = 0;
vector<int> list;

void print_list(vector<int> l) {
    if (l.size() == 0) return;
    printf("%d", l[0]);
    for (int i = 1; i < l.size(); i++)
        printf(", %d", l[i]);
    printf("\n");
}

void func(int remain, int c_val, int &list_num, vector<int> &l) {
    // 当或兑换完成时，输出兑换序列并跳出
    if (remain == 0) {
        print_list(l);
        list_num++;
        return;
    }
    // 没有再小的硬币可选了, 跳出
    if (c_val >= 3)
        return;

    int num = remain / COIN[c_val];
    for (int i = 0; i < num; i++)
        l.push_back(COIN[c_val]);
    for (int i = num; i >= 1; i--)
    {
        // 选i个当前面值硬币
        func(remain - COIN[c_val] * i, c_val + 1, list_num, l);
        l.pop_back();
    }
    // 不选择当前面值
    func(remain, c_val + 1, list_num, l);
}

int main() {
    scanf("%d", &n);
    func(n, 0, list_num, list);
    printf("总共有%d种兑换方式\n", list_num);
    return 0;
}