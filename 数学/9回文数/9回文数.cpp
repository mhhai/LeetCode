class Solution {
public:
	bool isPalindrome(int x) {
		//��һ��vector���洢�����
		if (x < 0)
			return false;
		vector<int> v;
		while (x > 0)
		{
			v.push_back(x % 10);
			x = x / 10;
		}
		int i = 0;  //ָ�������һ��Ԫ��
		int j = v.size() - 1;  //ָ���������һ��Ԫ��
		while (i < j)
		{
			if (v[i++] != v[j--])
				return false;
		}
		return true;
	}
};