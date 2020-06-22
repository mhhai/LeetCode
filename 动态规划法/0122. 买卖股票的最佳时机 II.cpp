//Ê¹ÓÃÌ°ÐÄ
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if (m < 2)
            return 0;
        int maxProfit = 0;
        for (int i = 1; i < m; ++i)
        {
            if (prices[i] > prices[i - 1])
                maxProfit += prices[i] - prices[i - 1];
        }
        return maxProfit;
    }
};