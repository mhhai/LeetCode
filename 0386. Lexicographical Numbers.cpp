//ʹ��dfs
//�ȷ��ʵ�ǰ�ڵ㣬�ٷ�����ߵ�һ���ڵ㣬�ٷ����ұߵĽڵ㣬���
//�������������
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