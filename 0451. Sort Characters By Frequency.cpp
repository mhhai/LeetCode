//ʹ�����ȼ�����
//��Ҫ�Ŀ��ǻ���string append���÷�
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> col;
        for (char i : s)
            col[i]++;
        priority_queue<pair<int, char>> Q;
        for (auto i : col)
            Q.push({ i.second, i.first });
        string ret;
        while (!Q.empty())
        {
            ret.append(Q.top().first, Q.top().second);
            Q.pop();
        }
        return ret;
    }
};

//�Ѳ�ͬ���ȵ��ַ����ַ����ŵ�һ��
//���հ����Ǵ�����
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> col;
        for (char i : s)
            col[i]++;
        vector<string> str(s.size() + 1);
        for (auto i : col)
        {
            str[i.second].append(i.second, i.first);
        }
        string ret;
        for (int i = str.size() - 1; i >= 1; --i)
        {
            if (!str[i].empty())
                ret += str[i];
        }
        return ret;
    }
};