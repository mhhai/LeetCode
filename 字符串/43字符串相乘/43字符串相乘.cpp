#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		int m = num1.size();
		int n = num2.size();
		//���ݹ��ɣ�num1��num2�˻�����󳤶�Ϊm + n����С����Ϊm + n - 1����Ϊ0����
		//����һ���ַ����������ɽ��
		int* tmp = new int(m + n);
		for (int i = 0; i < m + n; ++i)
		{
			tmp[i] = 0;
		}
		for (int i = m - 1; i >= 0; --i)
		{
			for (int j = n - 1; j >= 0; --j)
			{
				//num1[i] * num2[j]�Ľ������res[i + j] ��res[i + j + 1]֮��
				tmp[i + j + 1] = (tmp[i + j + 1] + (num1[i] - '0') * (num2[j] - '0')) % 10;
				tmp[i + j] += ((tmp[i + j + 1] + (num1[i] - '0') * (num2[j] - '0')) / 10);
			}
		}
		//��int����ת����ַ���
		string res;
		for (int i = 0; i < m + n; ++i)
		{
			if (i == 0 && tmp[i] == 0)
				continue;
			res += tmp[i] + '0';
		}
		delete tmp;
		return res;
	}
};

int main()
{
	Solution a;
	string b = "999";
	string c = "99";
	cout << a.multiply(b, c) << endl;
	system("pause");
}