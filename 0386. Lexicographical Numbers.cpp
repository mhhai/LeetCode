//使用dfs
//先访问当前节点，再访问左边第一个节点，再访问右边的节点，因此
//类似于先序遍历
class Solution {
public:
	vector<int> res;
	vector<int> lexicalOrder(int n) {
		for (int i = 1; i <= 9; ++i)
		{
			if (i <= n)
			{
				res.push_back(i);
				dfs(i, n);
			}
		}
		return res;
	}
	void dfs(int num, int n)
	{
		if (num > n)
			return;
		for (int i = 0; i <= 9; ++i)
		{
			int temp = num * 10 + i;
			if (temp > n)
				return;
			res.push_back(temp);
			dfs(temp, n);
		}
	}
};