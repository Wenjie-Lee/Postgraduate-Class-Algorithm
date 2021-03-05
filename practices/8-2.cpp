// practice 8-2
/*

*1
(([{}]))()
:0
*2
(}{)
:2
*2
(}(}
:4
*/

string brackets;
int num;

int main() {
	cin >> brackets;
	
	int k;
	while (!brackets.empty())
	{
		bool flag = false;				// 是否匹配
		k = 0;
		char c = brackets[0];			// 找到相同括号的最内层，从最内层往后匹配括号，避免匹配不对称
		while (k < brackets.size() && c == brackets[k])
			k++;
		k--;
		for (k; k < brackets.size(); k++)
		{
			if (brackets[k] - 1 == c	// c是‘(’， crackets[k] 是‘)’
				|| brackets[k] - 2 == c // c是‘[’， crackets[k] 是‘]’ 或者 c是‘{’， crackets[k] 是‘}’
				) {	
				flag = true;
				brackets.erase(brackets.begin() + k);
				brackets.erase(brackets.begin());
				break;
			}
		}
		if (!flag) {
			brackets.erase(brackets.begin());
			num++;
		}
	}
	cout << num << endl;
	return 0;
}