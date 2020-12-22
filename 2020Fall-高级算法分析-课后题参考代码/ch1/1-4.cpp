#include<iostream>
#include<string>
#include<vector>
using namespace std;
//��������ʾ
vector<string> vec;		//�洢������
int n;			//������ַ�������

bool islexicalorder() {
	int i = 0;
	// ÿ����Ԫ�ػ���Ƚ�
	while (i < vec.size()-1) {
		// ǰһλ���ں�һλ�����������ֵ���
		if (vec[i].compare(vec[i+1]) > 0) {
			return false;
		}
		i++;
	}
	return true;
}

bool islengthorder() {
	int i = 0;
	// ÿ����Ԫ�ػ���Ƚ�
	while (i < vec.size()-1) {
		// ǰһ��string�Ⱥ�һ��string�����������㳤����
		if (vec[i].size() > vec[i + 1].size())
			return false;
		i++;
	}
	return true;
}

int main()
{	string s;
    	bool flag1,flag2;
    	cin >> n;				//����n
	for (int i=0;i<n;i++)
	{	cin >> s;			//����һ���ַ���
        	vec.push_back(s);	//��ӵ�vec�ַ���������
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
