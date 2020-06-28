class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        int m = tokens.size();
        for (int i = 0; i < m; ++i)
        {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
                S.push(stoi(tokens[i]));
            }
            else if (tokens[i] == "+")
            {
                int a = S.top();
                S.pop();
                int b = S.top();
                S.pop();
                S.push(b + a);
            }
            else if (tokens[i] == "-")
            {
                int a = S.top();
                S.pop();
                int b = S.top();
                S.pop();
                S.push(b - a);
            }
            else if (tokens[i] == "*")
            {
                int a = S.top();
                S.pop();
                int b = S.top();
                S.pop();
                S.push(b * a);
            }
            else if (tokens[i] == "/")
            {
                int a = S.top();
                S.pop();
                int b = S.top();
                S.pop();
                S.push(b / a);
            }
        }
        return S.top();
    }
};