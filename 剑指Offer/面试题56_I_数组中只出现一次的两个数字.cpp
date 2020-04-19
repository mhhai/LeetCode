class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		vector<int> nums1;
		vector<int> nums2;
		vector<int> res;
		int tempRes = xOr(nums);
		//自左向右寻找第一个为1的位置
		int pos = 0;
		while (tempRes > 0)
		{
			pos++;
			if (tempRes % 2 == 1)
				break;
			tempRes = tempRes >> 1;
		}
		//遍历一遍数组，对每个数进行分配
		for (int i = 0; i < nums.size(); ++i)
		{
			int tempPos = pos;
			int tempNum = nums[i];
			while (tempPos > 1)
			{
				tempNum = tempNum >> 1;
				tempPos--;
			}
			if (tempNum % 2 == 1)
				nums1.push_back(nums[i]);
			else
				nums2.push_back(nums[i]);
		}
		res.push_back(xOr(nums1));
		res.push_back(xOr(nums2));
		return res;
	}

	int xOr(vector<int>& nums)
	{
		int res = 0;
		for (int i : nums)
			res ^= i;
		return res;
	}
};