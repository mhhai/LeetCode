//使用动态规划
//dp[i][j] = min(dp[i - 1][j] + dp[i][j - 1] + dp[i][j]) + 1;
//dp[i][j]代表word1[0...i]和word2[0...j]之间的编辑距离
//dp[i - 1][j]代表将word1[0...i - 1]和word2[0...j]之间的编辑距离，即对于word1的第i个字符，在word2最后添加了一个相同的字符
//dp[i][j - 1]代表word1[0...i]和word2[0...j - 1]之间的编辑距离，即对于word2的第j个字符，在word1最后添加了一个相同的字符
//dp[i - 1][j - 1]代表word1[0...i - 1]和word2[0...j - 1]之间的编辑距离，即对于word2的第j个字符，可以修改word1的第i个字符，使得这两个字符相同，或者这两个字符本来就相同
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; ++i)
        {
            dp[0][i] = i;
        }
        for (int i = 0; i <= m; ++i)
        {
            dp[i][0] = i;
        }
        //进行动态规划
        /*
        for(int i = 0; i <= m; ++i)
        {
            for(int j = 0; j <= n; ++j)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        */
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                //cout << dp[i][j] << " ";
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = Min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
            //cout << endl;
        }
        return dp[m][n];
    }

    int Min(int& a, int& b, int c)
    {
        int res = a;
        res = res < b ? res : b;
        res = res < c ? res : c;
        return res;
    }
};