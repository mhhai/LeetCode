//使用动态规划法，之前先了解暴力法的重叠子问题
class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
		for (int i = 0; i <= n; ++i)
		{
			dp[i][i] = 0;
			dp[0][i] = 0;
			dp[i][0] = 0;
		}

		//
		for (int j = 2; j <= n; ++j)   //按列填充  
			for (int i = j - 1; i >= 1; --i)
			{
				//在每轮循环中，计算的是dp[i][j]
				for (int k = i + 1; k <= j - 1; ++k)  //k表示不同的分割点
				{
					//cout << j << " " << i <<" " <<k <<endl;
					dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
				}
				//两端单独考虑，否则要对dp[i][i + 1] 初始化为0
				//以i作为分割点
				dp[i][j] = min(dp[i][j], i + dp[i + 1][j]);
				dp[i][j] = min(dp[i][j], j + dp[i][j - 1]);
			}
		return dp[1][n];  //注意返回值
	}
};