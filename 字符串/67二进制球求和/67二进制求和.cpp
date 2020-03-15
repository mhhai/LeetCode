#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		//��֤a�Ĵ�С�Ǵ��ڵ���b��
		if (b.size() > a.size())
		{
			a.insert(a.begin(), b.size() - a.size(), '0');
		}
		if (b.size() < a.size())
		{
			b.insert(b.begin(), a.size() - b.size(), '0');
		}
		int n = a.size();  //�����ַ�������ͬ�ĳ���
		string res(n, '0');
		int car = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			res[i] = (a[i] - '0' + b[i] - '0' + car) % 2 + '0';
			car = (a[i] - '0' + b[i] - '0' + car) / 2;
		}
		if (car == 1)
			res.insert((unsigned int)0, 1, '1');
		return res;
	}
};