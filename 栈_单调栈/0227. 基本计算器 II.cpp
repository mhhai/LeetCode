//�ȼ���Ӽ���
//�뷨�ǽ����������Ǹ���
//��Ȼ����׺���ʽת���ɺ�׺���ʽҲ�ǿ��еģ�����⻹�ǰ����ַ�������
//�ټ���˳���
class Solution {
public:
    int calculate(string s) {
        stack<int> S;
        char sign = '+';
        int num = 0;
        int m = s.size() - 1;
        int res = 0;
        for (int i = 0; i <= m; ++i)
        {
            //if(s[i] == ' ')  //������һ�䣬���һ�����ֺ������пո���û�취�����ж� 
                //continue;
            if (isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
                //cout << num << endl;
            }
            if (i == m || (!isdigit(s[i]) && s[i] != ' '))
            {
                //cout << i << endl;
                //cout << S.top() << endl;
                //cout << S.empty() << endl;
                //cout << "a" << endl;
                //string temp = "a";
                //temp[0] = s[i];
                //cout << temp << endl;
                //cout << "b" << endl;
                //cout << num << endl;
                if (sign == '+')
                {
                    S.push(num);
                }
                else if (sign == '-')
                {
                    S.push(-num);
                }
                else if (sign == '*')
                {
                    int temp = S.top();
                    S.pop();
                    S.push(temp * num);
                }
                else if (sign == '/')
                {
                    int temp = S.top();
                    //cout << temp << endl;
                    S.pop();
                    S.push(temp / num);
                }
                num = 0;
                sign = s[i];
            }
        }
        while (!S.empty())
        {
            res += S.top();
            S.pop();
        }
        return res;
    }
};