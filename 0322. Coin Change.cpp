//使用递归的方法
//dp[n]
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        int m = coins.size();
        int res = INT_MAX;
        for (int i = 0; i < m; ++i)
        {
            if (coinChange(coins, amount - coins[i]) == -1)
                continue;
            res = min(res, coinChange(coins, amount - coins[i]) + 1);
        }
        return res == INT_MAX ? -1 : res;
    }
};
//使用记忆化递归
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        recurssion(coins, amount, dp);
        return dp[amount];
    }

    int recurssion(vector<int>& coins, int amount, vector<int>& dp)
    {
        if (amount == 0)
            return 0;   //表示不需要再添加该元素了
        if (amount < 0)
            return -1;
        if (dp[amount] != INT_MAX)
            return dp[amount];
        //
        int res = INT_MAX;
        int m = coins.size();
        for (int i = 0; i < m; ++i)
        {
            if (recurssion(coins, amount - coins[i], dp) == -1)
                continue;
            res = min(res, recurssion(coins, amount - coins[i], dp) + 1);
        }
        dp[amount] = res == INT_MAX ? -1 : res;  //记忆
        return dp[amount];
    }
};

//使用动态规划法
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX - 1);
        //sort(coins.begin(), coins.end());
        dp[0] = 0;
        int m = coins.size();
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (i - coins[j] >= 0)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
            //cout << dp[i] << endl;
        }
        //cout <<(dp[amount] == INT_MAX - 1) <<endl;
        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
    }
};