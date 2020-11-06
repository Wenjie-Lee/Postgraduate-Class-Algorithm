// assignment 3-2

/*

算法思想： 运用DFS的思想
（1） 当已经选取出5个字母时，若满足公式且比当前答案的字典序要大，就保存这个结果；
（2） 在选取字母时，遍历字符串，挑选一个没有被选过的位置的字母加入密码字符串；
剪枝：若当前密码字符串的字典序已经小于当前的答案，就剪枝

输入样例：
1 ABCDEFGHIJKL
11700519 ZAYEXIWOVU
3072997 SOUGHT
1234567 THEQUICKFROG
0
样例输出：
LKEBA
YOXUZ
GHOST
no solution
0
*/

long long n; 
string str, password, res, min_str = "AAAAA", ns = "no solution";   // min_str最初为最小字典序
int map[30];
// int str_visit[12];
//vector<string> vec;

// 根据公式计算密码字符串的值, 题目保证了密码长度为5
long long cal(string str) {
    long long ans = 0;
    if (str.size() < 5) return ans;
    int x = -1;
    for (int i = 0; i < 5; i++) {
        // (str[i] - 'A' + 1) 即算出了该字母的序数
        ans -= pow((str[i] - 'A' + 1), i + 1) * x;
        x *= -1;
    }

    return ans;
}

void dfs(bool &has_result) {
    // 当选出了5个字母时，判断
    if (password.size() >= 5)
    {
        // 如果已经有了结果，就不再执行去了
        if (!has_result && cal(password) == n) {
            res = password;
            has_result = true;
        }
        //if (cal(password) == n) {
        //if (password > res)
        //res = password;
        //vec.push_back(password);
        //}
        return;
    }
    else {
        // 从序数大的字母开始循环，找到一个满足条件的结果就可以跳出了
        for (int i = 26; i >= 1; --i)
        {

            if (map[i] > 0)
            {
                map[i]--;
                password.push_back('A' + i - 1);
                dfs(has_result);
                map[i]++;
                password.pop_back();
            }
        }
        // for (int x = 0; x < str.size(); x++)
        // {
        //     // 若这个字母选过了，就跳过
        //     if (str_visit[x]) continue;
        //     // 是否选择str第i个字母
        //     password.push_back(str[x]);
        //     str_visit[x] = true;
        //     // 因为题目要选取的是字典序最大密码字符串，所以每次选出一个密码字符串(无论长度是否是5)
        //     // 就要和当前的答案进行比较，若字典序小于当前答案，则直接剪枝
        //     if (password > res)
        //         dfs();
        //     password.pop_back();
        //     str_visit[x] = false;
        // }
    }
}

int main() {
    clock_t start, end;
    do
    {
        // 初始化一些变量
        res = "AAAAA";
        memset(map, 0, sizeof(map));
        //vec.clear();

        cin >> n;
        if (n == 0) break;
        cin >> str;

        // 存储每个字母的个数
        for (int i = 0; i < str.size(); ++i)
            map[str[i] - 'A' + 1]++;

        start = clock();
        bool has_result = false;
        dfs(has_result);
        end = clock();
        cout << "time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
        if (res == "AAAAA") {
            cout << ns << endl;
        }
        else {
            cout << res << endl;
        }
    } while (true);

    return 0;
}