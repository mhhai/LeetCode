class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		if (nums.size() < 2)
			return res;
		int p = 0;
		int q = nums.size() - 1;
		int sum = 0;
		while (p < q)
		{
			sum = nums[p] + nums[q];
			if (sum > target)
				q--;
			else if (sum < target)
				p++;
			else
			{
				res.push_back(nums[p]);
				res.push_back(nums[q]);
				break;
			}
		}
		return res;
	}
};