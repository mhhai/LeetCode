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

	//splitTimeȡֵΪ0�� 1�� 2�� 3
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
		//����ʣ��λ�����м�֦
		//l - begin��ʾ��û���зָ���ַ���λ��
		//һ��ʼbeginΪ0
		//�ȼ����ټ�֦
		if (l - begin < 4 - splitTime || l - begin > 3 * (4 - splitTime))
			return;         //��ֻ�Ǽ�֦�������������е���������֦
		for (int i = 0; i < 3; ++i)
		{
			//��begin��ʼѡ��
			if (begin + i > l - 1)
				break;
			if (isValid(s, begin, begin + i))  //�ж��Ƿ��ܹ�ѡ�񣬲����֦
			{
				//cout << "begin: " <<begin << endl;
			   // cout << "i: " << i << endl;
				//cout << s.substr(begin, i + 1) << endl;
				path += s.substr(begin, i + 1);
				path.push_back('.');
				// cout << "path1: " << path << endl;
				backTrace(s, begin + i + 1, splitTime + 1, path);  //��һ���вź��м�֦������
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

		//���ַ���ת��������
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