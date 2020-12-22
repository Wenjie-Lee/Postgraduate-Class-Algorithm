#include <iostream>
#include <string>
using namespace std;
int main()
{
    string N;
    int n,i;
    cin >> N >> n;
    while (n--)
    {
        int len=N.length();
        for (i=0;i<len-1;i++)
            if (N[i]<N[i+1])
            {
                N.erase(N.begin()+i);
                break;
            }
        if (i==len-1)
            N.erase(N.end()-1);	 //É¾³ý×îºóÊý×Ö
    }
    cout << N << endl;
	return 0;
}
