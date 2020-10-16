#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

// 练习课1.3 
/*
    两个大整数字符串相乘，得一个大整数字符串并输出

    思想： 按手写乘法法则实现乘法算法。

    输入案例1
    33 34
    输出案例1
    1122
    Length: 4
    输入案例2
    72106547548473106236 982161082972751393
    输出案例2
    70820244829634538040848656466105986748
    Length: 38
*/

struct bign {
    int d[1000], len;
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign str2Bign(string str) {
    bign a;
    a.len = str.size();
    for (int i = 0; i < a.len; i++)
    {
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}

//bign add(bign a, bign b) {
//  bign c;
//  int carry = 0;      // 进位
//  for (int i = 0; i < a.len || i < b.len; i++)
//  {
//      int temp = a.d[i] + b.d[i] + carry;
//      c.d[c.len++] = temp % 10;
//      carry = temp / 10;
//  }
//  if (carry != 0)     // 若最后还有进位，就加到最高位
//  {
//      c.d[c.len++] = carry;
//  }
//  return c;
//}

bign multiply(bign a, bign b) {
    bign c;
    int dig = 0;
    // a
    for (int i = 0; i < a.len; i++)
    {
        int carry = 0;
        // b
        for (int j = 0; j < b.len; j++)
        {
            int temp = a.d[i] * b.d[j] + carry;
            c.d[dig + j] += temp;
            carry = c.d[dig + j] / 10;
            c.d[dig + j] %= 10;
            c.len = max(dig + j + 1, c.len);
        }
        while (carry != 0) {
            c.d[c.len++] += carry % 10;
            carry /= 10;
        }
        dig++;
    }
    return c;
}

void printBign(bign a) {
    for (int i = a.len - 1; i >= 0; i--)
    {
        cout << a.d[i];
    }
    cout << endl;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    bign a = str2Bign(str1);
    bign b = str2Bign(str2);

    bign d = multiply(a, b);

    printBign(d);
    cout << "Length: " << d.len << endl;

    return 0;
}