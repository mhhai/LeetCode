//第一个版本，无法去重
#include<algorithm>
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() < 3)
			return res;
		sort(nums.begin(), nums.end());

		int p = 0;
		int q = 0;
		for (int i = 0; i < nums.size() - 2; ++i)
		{
			p++;
			q = p + 1;
			while (q < nums.size())
			{
				if (nums[i] + nums[p] + nums[q] == 0)
				{
					res.push_back({ nums[i], nums[p], nums[q] });
					while (nums[p] == nums[q])
				}
				else if (nums[i] + nums[p] + nums[q] > 0)
				{
					break;
				}
				else
				{
					q++;
				}
			}
		}
		return res;
	}
};