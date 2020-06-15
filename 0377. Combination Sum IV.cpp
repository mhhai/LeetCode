//dfs的算法可以找出所有可能的组合，但是对本题来说，只要找到组合的个数
//在dfs的过程中，有很多重复的子问题，因此可以考虑使用动态规划
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (nums.empty())
			return 0;
		//若改用float或者double会有精度损失
		vector<unsigned long long> dp(target + 1, 0);   //dp[i]表示和为i的组合个数

		//判断该数组中的最大公约数
		int g = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			g = gcd(g, nums[i]);
		}
		//cout << g << endl;
		if (target % g != 0)
			return 0;
		dp[0] = 1;
		for (int i = 1; i <= target; ++i)
		{
			for (int j = 0; j < nums.size(); ++j)
			{
				if (nums[j] <= i)
					//dp[i] = (dp[i] >= INT_MAX - dp[i - nums[j]]) ? INT_MAX : dp[i] + dp[i - nums[j]];
					dp[i] += dp[i - nums[j]];  //当nums[j]的值为i时，dp[i] += dp[0]即多加了1
			}
		}
		return dp[target];
	}
	int gcd(int a, int b)
	{
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
};