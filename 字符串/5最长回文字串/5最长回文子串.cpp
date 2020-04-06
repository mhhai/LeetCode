//动态规划法，时间复杂度O(n^2)，空间复杂度O(n^2)
/*
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		vector< vector<bool> > dp(n, vector<bool>(n));
		//对dp进行初始化，按照子字符串的大小进行初始化
		string res;
		int end = 0;
		int maxLen = 0;
		for(int length = 1; length <= n; ++length)
		  for(int start = 0; start < n; ++start)
		  {
			  end = start + length - 1;
			  if(end >= n)
				break; //只跳出自己这层循环
			  if((length == 1 || length == 2 || dp[start + 1][end - 1]) && s.at(start) == s.at(end))
				{
					dp[start][end] = true;
					if(length > maxLen)
					{
					  res = s.substr(start, length);
					  maxLen = length;
					}
				}
			  else
				dp[start][end] = false;
		  }
		  return res;
	}
};
*/
//优化之后的动态规划法，时间复杂度O(n^2),空间复杂度(O(n))
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		vector<bool> dp(n);
		int maxLen = 0;
		string res;
		for (int i = n - 1; i >= 0; --i)
		{
			for (int length = n - i; length >= 1; --length)
			{
				if ((length == 1 || length == 2 || dp[i + length - 2]) && s.at(i) == s.at(i + length - 1))
				{
					dp[i + length - 1] = true;
					if (length > maxLen)
					{
						res = s.substr(i, length);
						maxLen = length;
					}
				}
				else
					dp[i + length - 1] = false;
				///cout << dp[i + length - 1] << endl;
			}
		}
		return res;
	}
};

#include<string>
class Solution {
public:
	string longestPalindrome(string s) {
		string res;
		int length = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			int len1 = extend(i, i, s); //n个位置
			int len2 = extend(i, i + 1, s); //n - 1个位置,代表扩展中心在两个字符中间
			int tempLength = max(len1, len2);
			if (length < tempLength)
			{
				length = tempLength;
				int start = i - (tempLength - 1) / 2;  //start要自己测试
				res = s.substr(start, length);
			}

		}
		return res;
	}

	int extend(int start, int end, string& s)  //返回字符串的长度而不是子字符在C++中易处理一些
	{
		while (start >= 0 && end <= s.size() - 1)
		{
			if (s[start] == s[end])
			{
				start--;
				end++;
			}
			else
				break;
		}
		return end - start - 1;
	}
};

//自己习惯的dp算法
//使用dp算法
class Solution {
public:
	string longestPalindrome(string s) {
		string res;
		res += s[0];
		int n = s.size();
		if (n <= 1)
			return s;
		vector<vector<bool>> table(n, vector<bool>(n));
		for (int i = 0; i < n; ++i)
			table[i][i] = true;
		int maxLen = 0;

		for (int i = 1; i < n; ++i)
			for (int j = 0; j < i; ++j)
			{
				//判断该字符串的长度 c[j,i]
				int len = i - j + 1;
				if (len < 3)
				{
					if (s[i] == s[j])
						table[j][i] = true;
					else
						table[j][i] = false;
				}
				else
				{
					if (table[j + 1][i - 1] && s[i] == s[j])
						table[j][i] = true;
					else
						table[j][i] = false;
				}
				if (table[j][i] && len > maxLen)
				{
					maxLen = len;
					res = s.substr(j, maxLen);
				}
			}
		return res;
	}
};