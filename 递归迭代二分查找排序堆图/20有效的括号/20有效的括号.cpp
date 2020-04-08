class Solution {
public:
	bool isValid(string s) {
		stack<char> S;
		if (s.size() & 0x1)
			return false;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				S.push(s[i]);  //��ջ
			else  //�Ƚϲ���ջջ��Ԫ��
			{
				if ((s[i] == ')' && S.top() == '(') || (s[i] == ']' && S.top() == '[') || (s[i] == '}' && S.top() == '{'))
					S.pop();
				else
					return false;
			}
		}
		if (S.empty())
			return true;
		return false;

	}
};