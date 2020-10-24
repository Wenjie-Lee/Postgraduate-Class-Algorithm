using namespace std;
const int maxn = 510;
int n, res, mp[30]{ 0 };    // 只有26个小写字母
char str_input[maxn], cstr[maxn];           // 题目给定长度不超过500 

void init() {
    res = 0;
    for (int i = 0; i < 26; i++)
    {
        mp[i] = 0;
    }
}

void mapping() {
    for (int i = 0; i < n; i++)
        mp[(int)(str_input[i] - 'a')]++;
}

int input(string path, string filename) {
    fstream file;

    file.open(path + filename);
    if (!file.is_open()) {
        cout << "open file failure" << endl;
        return NULL;
    }
    string num;
    file >> num;
    int n = atoi(num.c_str());
    for (int i = 0; i < n; i++)
        file >> str_input[i];
    file.close();
    return n;
}

void dfs(int depth, fstream &f) {
    if (depth >= n)
    {
        res++;
        /*for (int i = 0; i < n; i++)
            cout << cstr[i];
        cout << endl;*/
        for (int i = 0; i < n; i++)
            f << cstr[i];
        f << endl;
        return;
    }

    for (int i = 0; i < 26; i++)
    {
        if (mp[i] > 0)
        {
            cstr[depth] = i + 'a';
            mp[i]--;
            dfs(depth + 1, f);
            mp[i]++;
        }
    }
}

int main() {
    string str;
    string path = "E:\\tools\\Graduated\\algorithm\\Postraduate-Class-Algorithm\\assignment 2-2-Permutation with Repetition\\test\\";
    do
    {
        cout << "请输入文件名：" << endl;
        cin >> str;
        if (str == "END") break;
        n = input(path, str);
        // 初始化 map 序列
        init();
        // 处理字母序列
        mapping();

        fstream file;
        // permXX.in
        file.open(path + "output.txt", ios::app | ios::out);
        file << "output from: " << str << endl;
        
        dfs(0, file);
        file << res << endl;
        file.close();
        cout << "输出结束" << endl;
    } while (true);
    return 0;
}