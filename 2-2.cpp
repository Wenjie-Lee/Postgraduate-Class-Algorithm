// 练习1-2 求众数
/*
思想： 线性递增序列求众数，遍历序列的同时，使用map记录出现的数以及出现次数，
    再遍历map，将出现次数最大的数（可能不止一个）用vector记录下来
*/

int n, maxc = 0;
map<int, int> mp;
vector<pair<int, int> > vec;

int main() {
    scanf("%d", &n);
    int temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        // 创建关于数temp的索引
        if (mp.find(temp) != mp.end())
            mp[temp]++;
        else
            mp[temp] = 1;
    }

    for (pair<int, int> p : mp) {
        if (p.second > maxc)
        {
            maxc = p.second;
            vec.clear();
            vec.push_back(p);
        }
        else if (p.second == maxc) {
            vec.push_back(p);
        }
    }

    printf("序列中的众数： \n");
    for (pair<int, int> p : vec)
        printf("%d, 出现次数：%d\n", p.first, p.second);
    printf("\n");

    return 0;
}