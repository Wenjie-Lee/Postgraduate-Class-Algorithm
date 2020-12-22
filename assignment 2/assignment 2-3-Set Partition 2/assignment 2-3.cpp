// 作业 2-3 
int n, m;
double res = 0;

void input(string path, string filename) {
    fstream file;

    file.open(path + filename);
    if (!file.is_open()) {
        cout << "open file failure" << endl;
        return;
    }
    string N, M;
    file >> N >> M;
    n = atoi(N.c_str());
    m = atoi(M.c_str());
    
    file.close();
}

double partition(int n, int m) {
    // 不会存在不够分的情况，也不会存在一下都不分的情况
    if (n < m || m == 0) return 0;
    // 把n个元素放进1个集合，和把n个元素放进n个集合都是一种情况
    if (m == 1 || m == n) return 1;
    // 把n-1个分为m-1个集合，剩余1个算1个集合； 
    // 把n-1个分为m个集合，剩余1个数可以加入到这m个集合的任意一个，有m种情况；
    // 二者加起来就是所有的情况
    return partition(n - 1, m - 1) + m * partition(n-1, m);
}

int main() {
    string str;
    string path = "E:\\tools\\Graduated\\algorithm\\Postraduate-Class-Algorithm\\assignment 2-3-Set Partition 2\\test\\";
    do
    {
        cout << "请输入文件名：" << endl;
        cin >> str;
        if (str == "END") break;
        input(path, str);

        fstream file;
        // permXX.in
        file.open(path + "output.txt", ios::app | ios::out);
        file << "output from: " << str << endl;

        res = 0;
        res = partition(n, m);

        file << res << endl;
        file.close();
        cout << "输出结束" << endl;
    } while (true);
    return 0;
}