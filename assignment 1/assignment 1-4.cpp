// 练习课1.4 
/*
    思想：给定的输入字符串序列，以题目给定的两个排序条件排序后，与原序列相比。
         其中第一个排序条件：字典序，是stl::sort()的默认排序方式；
         第二个排序条件：长度，需要自己实现

    样例输入1：
    3
    a
    aa
    bbb
    样例输出1：
    both
    样例输入2：
    3
    aaa
    bb
    c
    样例输出2：
    islexicalorder
    样例输入3：
    3
    c
    bb
    aaa
    样例输出3：
    lengths
    样例输入4：
    3
    bbb
    c
    aaaa
    样例输出4：
    none
*/
int n;
bool alphabet = true, lengths = true;
vector<string> vec, vec2, vec3;

bool cmpLengths(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        vec.push_back(s);
        vec2.push_back(s);
        vec3.push_back(s);
    }

    sort(vec2.begin(), vec2.end());
    sort(vec3.begin(), vec3.end(), cmpLengths);

    for (int i = 0; i < n; i++)
    {
        //cout << str << endl;
        if (vec[i] != vec2[i]) {
            alphabet = false;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (vec[i] != vec3[i])
        {
            lengths = false;
            break;
        }
    }

    cout << "result: ";
    if (alphabet && lengths)
        cout << "both\n" << endl;
    else if (alphabet)
        cout << "islexicalorder" << endl;
    else if (lengths)
        cout << "lengths" << endl;
    else
        cout << "none" << endl;

    // 输出三个vector
    cout << "vec:" << endl;
    for each (string var in vec)
        cout << var << endl;
    cout << "vec2:" << endl;
    for each (string var in vec2)
        cout << var << endl;
    cout << "vec3:" << endl;
    for each (string var in vec3)
        cout << var << endl;

    return 0;
}