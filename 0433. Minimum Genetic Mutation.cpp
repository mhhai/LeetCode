//跟单词接龙一模一样
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string, int>> Q;
        unordered_set<string> S(bank.begin(), bank.end());
        vector<char> col = { 'A', 'C', 'G', 'T' };
        Q.push({ start, 0 });
        while (!Q.empty())
        {
            string temp = Q.front().first;
            //cout << "temp: " << temp << endl;
            int changeTime = Q.front().second;
            Q.pop();
            if (temp == end)
                return changeTime;
            for (int i = 0; i < 8; ++i)
            {
                char cur = temp[i];
                for (int j = 0; j < 4; ++j)
                {
                    //cout << j << endl;
                    char ch = col[j];
                    if (cur == ch)
                        continue;
                    else
                        temp[i] = ch;
                    if (S.find(temp) != S.end())
                    {
                        Q.push({ temp, changeTime + 1 });
                        S.erase(temp);
                    }
                }
                temp[i] = cur;
            }
        }
        return -1;
    }
};