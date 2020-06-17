//将s和t中所有的字符进行异或运算
//最终的结果就是被添加的字母的ASCII码值
class Solution {
public:
	char findTheDifference(string s, string t) {
		char res = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			res ^= s[i] ^ t[i];
		}
		res ^= t[t.size() - 1];
		return res;
	}

};