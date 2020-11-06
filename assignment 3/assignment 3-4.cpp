// assignment 3-4

/*

算法思想：从袋子里拿出球，和向袋子里放入球是等效的。
        运用DFS思想，先记录各个数字球的个数，然后从小到大依次选择
        （1） 当所有球都被放入袋中时，是边界条件；
        （2） 记录上一次放入的球的数字，从大于等于它的球中再选择一个放入或不放入，
            计算是否是满足幸运条件，满足则+1。进入下一步DFS
                剪枝技巧：（1） 第一个球必须为1，否则不会有幸运袋子产生；
                         （2） 选择一个球入袋后，下一次选的球数字要比这一次大或等于，
                            这样可以剪去例如 141（==114） 这样的重复计数

输入样例1：
3
1 1 1
样例输出1：
2
输入样例1：
5
1 1 2 4 4
样例输出1：

*/

const int maxn = 1010;
int n, sum = 0, product = 1, res = 0;
int mp[maxn], mp_count = 0;
vector<int> vec;

bool luck(int sum, int product) {
    return sum > product;
}

void dfs(int num, int sum, int product) {
    if (mp_count == 0) return;

    for (int i = num; i < n; i++) {
        if (mp[i] != 0) {
            int _sum = sum + i;
            int _product = product * i;
            mp[i]--;
            if (mp[i] == 0)
                mp_count--;
            if (luck(_sum, _product)) {
                res++;
                vec.push_back(i);
                for (int i = 0; i < vec.size(); i++)
                    printf("%d", vec[i]);
                printf("\n");
                // 下一位从i开始选，避免选择比i小的数上去，这样就会与之前的重复
                dfs(i, _sum, _product);
                vec.pop_back();
            }               
            if (mp[i] == 0)
                mp_count++;
            mp[i]++;
        }
    }
}

int main() {
    scanf("%d", &n);
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (mp[num] == 0)
            mp_count++;
        mp[num]++;
    }
    // 对数组排序后，第一个数字一定是1，不是的化就都不成立
    if (mp[1] == 0) res = 0;
    else {
        mp[1]--;
        if (mp[1] == 0) mp_count--;
        vec.push_back(1);
        dfs(1, 1, 1);
    }
    printf("%d\n", res);
    return 0;
}