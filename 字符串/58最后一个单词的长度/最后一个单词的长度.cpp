#include<string>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		int count = 0;
		for (int i = s.size() - 1; i >= 0; --i)
		{
			//�ж����һ���ַ��Ƿ�Ϊ��
			if (count == 0 && s[i] == ' ')
				continue;
			if (count != 0 && s[i] == ' ')
				return count;
			if (s[i] != ' ')
				++count;
		}
		return count;
	}
};