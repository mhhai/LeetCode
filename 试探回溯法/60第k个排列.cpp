//暴力回溯法
/*
class Solution {
public:
	string res;
	int k;
	int n;
	int count = 0;
	string getPermutation(int n, int k) {
		this->k = k;
		this->n = n;
		string path = "";
		bool* used = new bool[n];
		for (int i = 0; i < n; ++i)
			used[i] = false;
		backTrace(path, used);
		return res;
	}
	void backTrace(string& path, bool* used)
	{
		if (count >= k)
			return;
		if (path.size() == n && count < k - 1)
		{
			count++;
			return;
		}
		if (count == k - 1 && path.size() == n)
		{
			count++;
			res = path;
			return;
		}

		for (int i = 1; i <= n; ++i)
		{
			//
			if (!used[i - 1])
			{
				used[i - 1] = true;
				path.push_back(i + '0');
				backTrace(path, used);
				path.pop_back();
				used[i - 1] = false;
			}
		}
	}
};
*/

class Solution {
public:
	string res;
	//int k;
	string getPermutation(int n, int k) {
		bool* used = new bool[n];
		for (int i = 0; i < n; ++i)
			used[i] = false;
		string path = "";
		backTrace(path, used, n, k);
		return res;
	}

	void backTrace(string path, bool* used, int n, int k)
	{
		cout << path << endl;
		if (path.size() == n)
		{
			res = path;
			return;
		}
		int remain = factorial(n - path.size() - 1); //这个remain是说第一个分支的remain，其他分                                                      //支的remain在循环内计算
		//选择哪个分支
		for (int i = 1; i <= n; i++)
		{
			//第二分支用于搜寻，第三分支依然需要剪枝
			if (used[i - 1])
				continue;
			if (k > remain)
			{
				k -= remain; //剪枝, 在下一轮循环中选择
				continue;
			}
			//k <= remain 在当前分支类
			used[i - 1] = true;
			path.push_back('0' + i);
			backTrace(path, used, n, k);
			//used[i - 1] = false;  这一步不加很重要，由于path维持了一个完整的排列，所以
			//才能够使用位运算来剪枝
			//cout << k <<endl;
			//最终k值为1
		}
	}

	int factorial(int n)
	{
		int res = 1;
		while (n > 0)
		{
			res *= n;
			n--;
		}
		return res;
	}
};