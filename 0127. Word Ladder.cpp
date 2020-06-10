//使用BFS
//BFS也有一种贪心的思想，一旦找到就是最短路径了
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> Q;
        unordered_set<string> S(wordList.begin(), wordList.end());
        Q.push({ beginWord, 1 });
        while (!Q.empty())
        {
            string temp = Q.front().first;
            int length = Q.front().second;
            if (temp == endWord)
                return length;
            Q.pop();
            for (int i = 0; i < temp.size(); ++i)
            {
                for (char ch = 'a'; ch <= 'z'; ++ch)
                {
                    char cur = temp[i];
                    if (temp[i] == ch)
                        continue;
                    else
                        temp[i] = ch;
                    if (S.find(temp) != S.end())  //说明找到了可以转换的单词，将此单词放在Q中
                    {
                        Q.push({ temp, length + 1 });
                        S.erase(temp);
                    }
                    temp[i] = cur;
                }
            }
        }
        return 0;
    }
};