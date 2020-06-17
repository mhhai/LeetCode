//使用动态规划法
//寻找最长的子序列
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int up = 1;
		int down = 1;
		int length = nums.size();
		if (length == 0)
			return 0;
		for (int i = 1; i < length; ++i)
		{
			if (nums[i] > nums[i - 1])
				up = down + 1;
			else if (nums[i] < nums[i - 1])
				down = up + 1;
		}
		return max(down, up);
	}
};