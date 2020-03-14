//�������ݷ�
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
		int remain = factorial(n - path.size() - 1); //���remain��˵��һ����֧��remain��������                                                      //֧��remain��ѭ���ڼ���
		//ѡ���ĸ���֧
		for (int i = 1; i <= n; i++)
		{
			//�ڶ���֧������Ѱ��������֧��Ȼ��Ҫ��֦
			if (used[i - 1])
				continue;
			if (k > remain)
			{
				k -= remain; //��֦, ����һ��ѭ����ѡ��
				continue;
			}
			//k <= remain �ڵ�ǰ��֧��
			used[i - 1] = true;
			path.push_back('0' + i);
			backTrace(path, used, n, k);
			//used[i - 1] = false;  ��һ�����Ӻ���Ҫ������pathά����һ�����������У�����
			//���ܹ�ʹ��λ��������֦
			//cout << k <<endl;
			//����kֵΪ1
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