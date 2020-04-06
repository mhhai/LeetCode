#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1 || s.size() == 0)
			return s;
		vector<string> S(min(numRows, (int)s.size()));
		string res;
		int p = 0;
		bool isGoingDown = false;
		for (int i = 0; i < s.size(); ++i)
		{
			S[p] += s.at(i);
			if (p == 0 || p == numRows - 1)
				isGoingDown = !isGoingDown;
			p = isGoingDown ? ++p : --p;
		}
		for (int i = 0; i < S.size(); ++i)
			res += S[i];
		return res;
		cout << INT_MAX;
	}
};