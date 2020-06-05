class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int flag = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                if (flag == 1)
                    count++;
                flag = 0;
            }
            else
                flag = 1;
        }
        if (flag == 1)
            count++;
        return count;
    }
};