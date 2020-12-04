
//#include <direct.h>q
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
//#include <map>
//#include <queue>
#include <algorithm>
//#include <fstream>
//#include <functional>
//#include <time.h>

using namespace std;

// assignment 4-6
/*
边界：
    （1） 没有饼干时，算是1种平分策略
状态转移函数：
    dp[数字位数][当前数字%n余数]
    （1）s[i-1]=='X',从0~9都计算一遍当前数字%n的余数，
        记录dp[i][余数]=sum(dp[i-1][所有余数])；
    （2）s[i-1]!='X',就计算当前位情况下数字%n的余数，
        记录dp[i][余数]=sum(dp[i-1][所有余数])；

*1
49X 3
:3
*2
X9X 3
:34
*3
9999999999999999X 3 (17位)
:4
*/
const char X = 'X';
// 第二维存放的是当前数 %n 后的结果，即当前部分数字不能平分的情况，
// 由于n未知，所有范围较大
long long dp[20][10000];
int main() {
    string s;
    int n, k = 0;
    cin >> s >> n;
    int len = s.size();
    // boundary init 没有饼干时也算是能平分，没有余数，所以dp[0][0] = 1
    dp[0][0] = 1;

    for (int i = 1; i <= len; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t;
            if (s[i - 1] == X) {
                for (int k = 0; k < 10; k++)
                {
                    t = (j * 10 + k) % n;
                    dp[i][t] += dp[i - 1][j];
                }
            }
            else {
                t = (j * 10 + (s[i - 1] - '0')) % n;
                dp[i][t] += dp[i - 1][j];
            }
        }
    }
    // 题目保证至少有1种，所有最后一定能除尽，第二维为0
    printf("%lld", dp[len][0]);
    return 0;
}