class Solution {
public:
	int myAtoi(string str) {
		int i = 0;
		int res = 0;
		int flag = 1;
		while (str[i] == ' ')  //����ո�
			i++;
		if (str[i] == '-')
			flag = -1;
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (i < str.size() && '0' <= str[i] && str[i] <= '9')
		{
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0') > 7))
				return flag == -1 ? INT_MIN : INT_MAX;
			res = res * 10 + (str[i] - '0');
			//�ж��Ƿ�����
			cout << i << endl;
			i++;
		}
		return flag == -1 ? -res : res;
	}
};