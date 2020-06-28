//使用动态规划法
class Solution {
public:
    string longestPalindrome(string s) {
        int m = s.size();
        vector<vector<bool>> isPalindrome(m, vector<bool>(m, false));
        int maxLength = 1;
        int start = 0;
        for (int j = 1; j < m; ++j)
            for (int i = 0; i <= j; ++i)
            {
                int length = j - i + 1;
                if (length == 1 || (length == 2 && s[i] == s[j]))
                    isPalindrome[i][j] = true;
                else
                    isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]) ? true : false;
                if (isPalindrome[i][j] == true)
                {
                    if (length > maxLength)
                    {
                        maxLength = length;
                        start = i;
                    }
                }
            }
        return s.substr(start, maxLength);
    }
};