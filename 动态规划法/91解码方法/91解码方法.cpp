//µÚÒ»°æ
#include<string>
using namespace std;
class Solution {
public:
	//int count = 0;
	int numDecodings(string s) {
		if (s == "0")
			return 0;

		int res = backTrace(s, s.size() - 1);
		return res;
	}

	int backTrace(string s, int pos)
	{
		if (pos == 0)
			return 1;
		if (('3' <= s[pos - 1] && s[pos - 1] <= '9') || s[pos - 1] == '0')
		{
			return backTrace(s, pos - 1);
		}
		else if ('1' <= s[pos - 1]  && s[pos - 1] <= '2' &&
			'0' <= s[pos] && s[pos] <= '6')
		{
			return backTrace(s, pos - 1) + 1;
		}
		return 0;
	}
};