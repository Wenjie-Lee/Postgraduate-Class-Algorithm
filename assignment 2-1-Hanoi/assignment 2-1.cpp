#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

char a = 'A', b = 'B', c = 'C';
// 将n个盘从A全部送到C
// a原位置， b辅助，c目标位置
void hanoi(char a, char b, char c, int n, fstream &f) {
    // 递归出口
    if (n < 1) return;
    hanoi(a, c, b, n - 1, f);
    //printf("%d %c %c\n", n, a, c);
    f << n << " " << a << " " << c << endl;
    hanoi(b, a, c, n - 1, f);
}

int input_hanoi(string path, string filename) {
    fstream file;
    string data;
    path += filename;

    file.open(path);
    if (!file.is_open()) {
        cout << "open file failure" << endl;
        return NULL;
    }
    while (!file.eof())
        file >> data;
    file.close();
    int n = atoi(data.c_str());
    return n;
}

int main() {
    string str;
    string path = "E:\\tools\\Graduated\\algorithm\\Postraduate-Class-Algorithm\\assignment 2-1-Hanoi\\test\\";
    do
    {
        cout << "请输入文件名：" << endl;
        cin >> str;
        if (str == "END") break;
        int n = input_hanoi(path, str);
        fstream file;
        file.open(path + "output.txt", ios::app | ios::out);
        file << "output from: " << str << endl;
        hanoi(a, c, b, n, file);
        file.close();
        cout << "输出结束" << endl;
    } while (true);
    cout << "程序结束" << endl;
    return 0;
}