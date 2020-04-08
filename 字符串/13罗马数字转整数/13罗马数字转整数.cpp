class Solution {
public:
	int romanToInt(string s) {
		unordered_map<string, int> roman = {
			{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9},
			{"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90},
			{"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900},
			{"M", 1000}
		};
		int res = 0;
		//������ɨ���ַ����������ַ�������һ���ַ����ж�
		int i = 0;
		while (i < s.size())
		{
			if (roman.find(s.substr(i, 2)) != roman.end())
			{
				res += roman[s.substr(i, 2)];
				i += 2;
			}
			else
			{
				res += roman[s.substr(i, 1)];
				i += 1;
			}
		}
		return res;
	}
};