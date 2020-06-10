//ʹ��BFS
//BFSҲ��һ��̰�ĵ�˼�룬һ���ҵ��������·����
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
                    if (S.find(temp) != S.end())  //˵���ҵ��˿���ת���ĵ��ʣ����˵��ʷ���Q��
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