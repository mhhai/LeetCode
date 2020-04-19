class Solution {
public:
	bool isStraight(vector<int>& nums) {
		//ÅÅĞò
		sort(nums.begin(), nums.end());
		int pos = 0;
		int count = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] == 0)
				count++;
			else
			{
				pos = i;
				break;
			}
		}
		int sum = 0;
		for (int i = pos + 1; i < nums.size(); ++i)
		{
			if (nums[i] == nums[i - 1])
				return false;
			else
				sum += nums[i] - nums[i - 1] - 1;
		}
		if (count >= sum)
			return true;
		return false;
	}
};