class Solution {
public:
	string reverseWords(string s) {
		string res = "";
		int count = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == ' ')
				count++;
		}
		if (count == s.size())
			return res;
		int p = 0, q = s.size() - 1;
		//去除开头的空格
		while (s[p] == ' ')
			p++;
		while (s[q] == ' ')
			q--;
		//遍历s，找到单词，并将其反转
		string temp = "";//用来保存单词
		for (int i = p; i <= q; ++i)
		{
			if (s[i] != ' ')
				temp += s[i];
			else
			{
				//继续找空格
				//int j = i; //j是第一个空格的位置
				while (s[i] == ' ')
					i++;
				i--;
				swap(temp);
				res += temp;
				res += " ";
				temp = "";
			}
		}
		swap(temp);
		res += temp;
		swap(res);
		return res;
	}

	void swap(string& s)
	{
		int p = 0, q = s.size() - 1;

		while (p < q)
		{
			char temp = s[p];
			s[p] = s[q];
			s[q] = temp;
			p++;
			q--;
		}

	}
};