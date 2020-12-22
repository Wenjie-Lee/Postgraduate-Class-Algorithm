#include<iostream>
#include<string>
#include<vector>
using namespace std;
//求解问题表示
vector<string> vec;		//存储主数据
int n;			//输入的字符串个数

bool islexicalorder() {
	int i = 0;
	// 每两个元素互相比较
	while (i < vec.size()-1) {
		// 前一位大于后一位，即不满足字典序
		if (vec[i].compare(vec[i+1]) > 0) {
			return false;
		}
		i++;
	}
	return true;
}

bool islengthorder() {
	int i = 0;
	// 每两个元素互相比较
	while (i < vec.size()-1) {
		// 前一个string比后一个string长，即不满足长度序
		if (vec[i].size() > vec[i + 1].size())
			return false;
		i++;
	}
	return true;
}

int main()
{	string s;
    	bool flag1,flag2;
    	cin >> n;				//输入n
	for (int i=0;i<n;i++)
	{	cin >> s;			//输入一个字符串
        	vec.push_back(s);	//添加到vec字符串向量中
    	}
    	flag1=islexicalorder();
    	flag2=islengthorder();
	if(flag1 && flag2)
        cout << "both";
    else if(flag1)
        cout << "islexicalorder";
    else if(flag2)
        cout << "lengths";
    else
        cout << "none";
    return 0;
}
