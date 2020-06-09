//01背包问题
//动态规划
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            sum += nums[i];
        if (sum & 0x1)
            return false;
        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= target; ++j)
            {
                dp[i][j] = dp[i - 1][j] || (nums[i - 1] == j) || (nums[i - 1] < j && dp[i - 1][j - nums[i - 1]]);
                //cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[n][target];

    }
};

//优化
//01背包问题
//动态规划
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            sum += nums[i];
        if (sum & 0x1)
            return false;
        int target = sum / 2;
        //vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        vector<bool> dp(target + 1, false);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = target; j >= 1; --j)
            {
                //dp[i][j] = dp[i - 1][j] || (nums[i - 1] == j) || (nums[i - 1] < j && dp[i - 1][j - nums[i - 1]]);
                //cout << dp[i][j] << " ";
                dp[j] = dp[j] || (nums[i - 1] == j) || (nums[i - 1] < j && dp[j - nums[i - 1]]);
            }
            //cout << endl;
        }
        return dp[target];
        //return dp[n][target];

    }
};