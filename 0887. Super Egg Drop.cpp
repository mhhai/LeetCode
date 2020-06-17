//简单的动态规划相当于优化之后的暴力法
//因为把每一个结果都存起来了
class Solution {
public:
	int superEggDrop(int K, int N) {
		vector<vector<int>> dp(K + 1, vector<int>(N + 1, INT_MAX));
		for (int i = 0; i < N + 1; ++i)
		{
			dp[0][i] = 0;
			dp[1][i] = i;
		}
		for (int i = 0; i < K + 1; ++i)
			dp[i][0] = 0;
		//填充其他的
		for (int k = 2; k <= K; ++k)
		{
			for (int n = 1; n <= N; ++n)
			{
				int left = 1;
				int right = n;
				//想找的是碎了 <= 没碎的最大值
				//dp[k - 1][i - 1] <= dp[k][n - i];
				//dp[k - 1][mid - 1] <= dp[k][n - mid]
				while (left < right)
				{
					int mid = left + (right - left) / 2;
					int b = dp[k - 1][mid - 1];  //b代表在mid处蛋碎了，需要扔的鸡蛋次数, 递增
					int nb = dp[k][n - mid];  //nb表示在mid处蛋没碎，需要扔的鸡蛋次数，递减
					if (b < nb)
						left = mid + 1;
					else if (b > nb)
						right = mid - 1;
					else
						left = right = mid;
				}
				dp[k][n] = min(max(dp[k - 1][left - 1], dp[k][n - left]), max(dp[k - 1][right - 1], dp[k][n - right])) + 1;
			}
		}
		return dp[K][N];
	}
};