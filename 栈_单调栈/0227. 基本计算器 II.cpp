//先计算加减法
//想法是将减法看做是负号
//虽然将中缀表达式转换成后缀表达式也是可行的，这道题还是按照字符串来解
//再计算乘除法
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
            //if(s[i] == ' ')  //若有这一句，最后一个数字后面若有空格，则没办法进行判断 
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