#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<string> res;
	vector<string> restoreIpAddresses(string s) {
		string path;
		backTrace(s, 0, 0, path);
		return res;
	}

	//splitTime取值为0， 1， 2， 3
	void backTrace(string s, int begin, int splitTime, string path)
	{
		int l = s.size();
		if (begin == l)
		{
			if (splitTime == 4)
			{
				path.pop_back();
				res.push_back(path);

			}
			return;
		}
		//根据剩余位数进行剪枝
		//l - begin表示还没进行分割的字符串位数
		//一开始begin为0
		//先加入再剪枝
		if (l - begin < 4 - splitTime || l - begin > 3 * (4 - splitTime))
			return;         //这只是剪枝条件，代码运行到这里才算剪枝
		for (int i = 0; i < 3; ++i)
		{
			//从begin开始选择
			if (begin + i > l - 1)
				break;
			if (isValid(s, begin, begin + i))  //判断是否能够选择，不算剪枝
			{
				//cout << "begin: " <<begin << endl;
			   // cout << "i: " << i << endl;
				//cout << s.substr(begin, i + 1) << endl;
				path += s.substr(begin, i + 1);
				path.push_back('.');
				// cout << "path1: " << path << endl;
				backTrace(s, begin + i + 1, splitTime + 1, path);  //这一步中才含有剪枝的内容
				path.pop_back();
				for (int j = begin + i; j >= begin; --j)
					path.pop_back();
				// cout << "path2:" << path << endl;
			}
		}
	}

	bool isValid(string s, int begin, int end)
	{
		if (end - begin + 1 > 1 && s[begin] == '0')
			return false;

		//把字符串转换成数字
		int res = 0;

		while (begin <= end) {
			res = res * 10 + s[begin] - '0';
			begin++;
		}
		cout << "res: " << res << endl;
		if (res > 255)
			return false;
		return true;
	}
};