#include<iostream>
#include<string>
#include<vector>
using namespace std;
//暴力法，生成所有可能的括号集合，判断该每一个序列是不是有效的
/*
class Solution {
public:
	vector<string> res;
	int n;
	vector<string> generateParenthesis(int n) {
		this->n = n;
		char* component = new char[2 * n];
		generateAllParenthesis(component, 0);
		return res;
	}

	void generateAllParenthesis(char* component, int pos)
	{
		if (pos == 2 * n)
		{
			if (isValid(component))
			{
				res.push_back(static_cast<string>(component));
			}
			return;
		}
		component[pos] = '(';
		generateAllParenthesis(component, pos + 1);
		component[pos] = ')';
		generateAllParenthesis(component, pos + 1);
	}

	bool isValid(char* component)
	{
		int balance = 0;
		for (int i = 0; i < 2 * n; ++i)
		{
			if (component[i] == '(')
				balance++;
			else
				balance--;
			if (balance < 0 || balance > n)
			{
				return false;
			}
		}
		return balance == 0;
	}
};
*/
//试探回溯法
/*
class Solution {
public:
	vector<string> res;
	int n;

	vector<string> generateParenthesis(int n) {
		this->n = n;
		int balance = 0;
		//char* component = new char[2 * n];
		generateAllParenthesis("", 0, 0);
		return res;
	}

	void generateAllParenthesis(string cur, int open, int close)
	{

		if (cur.size() == 2 * n)
		{
			res.push_back(cur);
			return;
		}
		if (open < n)
		{
			generateAllParenthesis(cur + '(', open + 1, close);
		}
		if (close < open)
		{
			generateAllParenthesis(cur + ')', open, close + 1);
		}
	}
};
*/
//动态规划法
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<vector<string>> dp(n + 1); //每一个元素保留的是所在下标可能的结果
		dp[0] = { "" };
		dp[1] = { "()" };
		for (int i = 2; i <= n; ++i)
			for (int j = 0; j < i; ++j)
				for (string p : dp[j])
					for (string q : dp[i - j - 1])
						dp[i].push_back('(' + p + ')' + q);
		return dp[n];
	}
};

int main()
{
	Solution a;
	vector<string> res;
	res = a.generateParenthesis(3);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	system("pause");
}