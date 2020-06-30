//先计算加减法
//想法是将减法看做是负号
//虽然将中缀表达式转换成后缀表达式也是可行的，这道题还是按照字符串来解
//再计算乘除法
class Solution {
public:
    int calculate(string s) {
        int start = 0;
        return recurse(s, start);
    }

    int recurse(string& s, int& i)  //i是索引,必须是引用格式的，因为i是
    {
        stack<int> S;
        char sign = '+';
        int num = 0;
        int m = s.size() - 1;
        int res = 0;
        for (i; i <= m; ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
                num = num * 10 + (s[i] - '0');
            if (s[i] == '(')
            {
                num = recurse(s, ++i);
                i++;
            }

            if (i == m || (!(s[i] >= '0' && s[i] <= '9')) && s[i] != ' ')
            {
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
                    S.pop();
                    S.push(temp / num);
                }

                num = 0;
                sign = s[i];
            }
            if (s[i] == ')')
            {
                break;
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