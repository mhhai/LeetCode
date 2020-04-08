//暴力法
/*
class Solution {
public:
	string intToRoman(int num) {
		string res = "";
		vector<vector<string>> str = {
			{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
			{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
			{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
			{"", "M", "MM", "MMM"}
		};
		int i = 0;
		while(num > 0)
		{
			int a = num % 10;
			res.insert(0, str[i++][a]);
			num = num / 10;
		}
		return res;
	}
};
*/
//贪心算法
class Solution {
public:
	string intToRoman(int num) {
		string res = "";
		vector<string> str = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		vector<int> inum = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

		for (int i = 0; i < 13; ++i)
		{
			while (num >= inum[i])
			{
				res += str[i];
				num -= inum[i];
			}
		}
		return res;
	}
};