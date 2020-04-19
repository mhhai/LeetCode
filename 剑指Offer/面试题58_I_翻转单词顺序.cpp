class Solution {
public:
	string reverseWords(string s) {
		string res = "";
		int count = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == ' ')
				count++;
		}
		if (count == s.size())
			return res;
		int p = 0, q = s.size() - 1;
		//ȥ����ͷ�Ŀո�
		while (s[p] == ' ')
			p++;
		while (s[q] == ' ')
			q--;
		//����s���ҵ����ʣ������䷴ת
		string temp = "";//�������浥��
		for (int i = p; i <= q; ++i)
		{
			if (s[i] != ' ')
				temp += s[i];
			else
			{
				//�����ҿո�
				//int j = i; //j�ǵ�һ���ո��λ��
				while (s[i] == ' ')
					i++;
				i--;
				swap(temp);
				res += temp;
				res += " ";
				temp = "";
			}
		}
		swap(temp);
		res += temp;
		swap(res);
		return res;
	}

	void swap(string& s)
	{
		int p = 0, q = s.size() - 1;

		while (p < q)
		{
			char temp = s[p];
			s[p] = s[q];
			s[q] = temp;
			p++;
			q--;
		}

	}
};