#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
struct DataStruct				//定义的数据结构
{	vector<string> data;		//用向量存放元素
	map<string,int> ht;			//用map存放元素的下标
};
void Insert(DataStruct &ds,string str)		//插入元素str
{	ds.data.push_back(str);
	int i=ds.data.size()-1;					//获取最后元素的下标
	ds.ht[str]=i;
}
bool Searchi(DataStruct ds,int i,string &str)	//查找下标为i的元素str
{	if(i<0 || i>=ds.data.size())
		return false;
	str=ds.data[i];
	return true;
}
int Searchs(DataStruct ds,string &str)		//查找值为str的元素下标
{	map<string,int>::iterator it;
	it=ds.ht.find(str);
	if (it!=ds.ht.end())
		return it->second;
	else
		return -1;
}
bool Delete(DataStruct &ds,string str)		//删除元素str
{	int i=Searchs(ds,str);					//查找元素str的下标
	if(i==-1) return false;					//没有str元素返回false
	int j=ds.data.size()-1;					//求尾元素下标
	ds.data[i]=ds.data[j];					//i下标元素与尾元素替代
	ds.ht[ds.data[j]]=i;					//修改哈希表中原来尾元素的下标
	ds.data.pop_back();					//从data中删除尾元素
}
void Display(DataStruct ds)				//输出所有元素
{	vector<string>::iterator it;
	for (it=ds.data.begin();it!=ds.data.end();it++)
		cout << *it << " ";
	cout << endl;
}
void main()
{
	DataStruct ds;
	string str;
	cout << "实验结果" << endl;	
	Insert(ds,"Mary");
	Insert(ds,"Smitch");
	Insert(ds,"John");
	Insert(ds,"Anany");
	cout << "  " << "依次插入Mary,Smitch,John,Anany" << endl;
	cout << "  元素表: "; Display(ds);
	str="John";
	cout << "  " << str << "的下标:" << Searchs(ds,str) << endl;
	cout << "  删除" << str << endl;
	Delete(ds,str);
	cout << "  删除后的元素表: "; Display(ds);
} 
