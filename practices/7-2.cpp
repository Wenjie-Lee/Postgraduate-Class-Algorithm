// practice 7-2

/*
删数问题，给定一个n位的（正）整数d，从中删去k<=n位，使剩余位按原位置排列组成一个新数，
且确保此数最小

2 500123
:12
2 92131
:131
1 9152
:
*/
int k;
string str;

int main() {
    cin >> k >> str;

    while (k--)
    {
        while (str.length() > 0 && str[0] == '0')
            str.erase(str.begin());
        int i, len = str.length();
        for (i = 0; i < len - 1; i++)
        {
            if (str[i + 1] < str[i])
            {
                str.erase(str.begin() + i);
                break;
            }
        }
        if (i==len-1)
            str.erase(str.end()-1);
    }
    cout << str << endl;
    return 0;
}