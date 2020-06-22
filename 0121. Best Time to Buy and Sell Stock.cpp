//使用动态规划
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if (m < 2)
            return 0;
        vector<int> dp(m, 0);
        int minPrice = prices[0];
        for (int i = 1; i < m; ++i)
        {
            minPrice = min(minPrice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minPrice);
        }
        return dp[m - 1];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int maxProfit = 0;
        int m = prices.size();
        //希望维护一个左边的最小值
        int left = 0;
        for (int i = 1; i < m; ++i)
        {
            if (prices[i] - prices[left] < 0)
            {
                left = i;
            }
            else
            {
                maxProfit = max(maxProfit, prices[i] - prices[left]);
            }
        }
        return maxProfit;

    }
};