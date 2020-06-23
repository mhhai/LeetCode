//ʹ�ö�̬�滮
//dp[i][j] = min(dp[i - 1][j] + dp[i][j - 1] + dp[i][j]) + 1;
//dp[i][j]����word1[0...i]��word2[0...j]֮��ı༭����
//dp[i - 1][j]����word1[0...i - 1]��word2[0...j]֮��ı༭���룬������word1�ĵ�i���ַ�����word2��������һ����ͬ���ַ�
//dp[i][j - 1]����word1[0...i]��word2[0...j - 1]֮��ı༭���룬������word2�ĵ�j���ַ�����word1��������һ����ͬ���ַ�
//dp[i - 1][j - 1]����word1[0...i - 1]��word2[0...j - 1]֮��ı༭���룬������word2�ĵ�j���ַ��������޸�word1�ĵ�i���ַ���ʹ���������ַ���ͬ�������������ַ���������ͬ
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
        //���ж�̬�滮
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