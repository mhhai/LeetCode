//��s��t�����е��ַ������������
//���յĽ�����Ǳ���ӵ���ĸ��ASCII��ֵ
class Solution {
public:
	char findTheDifference(string s, string t) {
		char res = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			res ^= s[i] ^ t[i];
		}
		res ^= t[t.size() - 1];
		return res;
	}

};