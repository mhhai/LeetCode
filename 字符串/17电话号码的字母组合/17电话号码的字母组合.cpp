class Solution {
public:
	vector<string> table = { "abc", "def" };
	string path = "";
	vector<string> result;
	vector<string> letterCombinations(string digits) {
		backTrace(digits, 0);
		return result;
	}

	void backTrace(string digit, int pos)
	{
		if (pos == digit.size())
		{
			result.push_back(path);
			return;
		}
		for (int i = 0; i < table[digit[pos] - '2'].size(); ++i)
		{
			path += table[digit[pos] - '2'][i];
			backTrace(digit, pos + 1);
			path.pop_back();
		}
	}
};