//Á½´Î±éÀú
class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> col;
		for (int i = 0; i < s.size(); ++i)
		{
			col[s[i]]++;
		}
		for (int i = 0; i < s.size(); ++i)
		{
			if (col[s[i]] == 1)
				return i;
		}
		return -1;

	}
};