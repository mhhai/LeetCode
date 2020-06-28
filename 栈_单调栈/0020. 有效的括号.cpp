class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        int m = s.size();
        for (int i = 0; i < m; ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                S.push(s[i]);
            else if (s[i] == ')')
            {
                if (S.empty() || S.top() != '(')
                    return false;
                else
                    S.pop();
            }
            else if (s[i] == ']')
            {
                if (S.empty() || S.top() != '[')
                    return false;
                else
                    S.pop();
            }
            else if (s[i] == '}')
            {
                if (S.empty() || S.top() != '{')
                    return false;
                else
                    S.pop();
            }
        }
        return S.empty() ? true : false;
    }
};