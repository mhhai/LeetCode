class Solution {
public:
	void sortColors(vector<int>& nums) {
		int pFirst = 0;
		int pSecond = nums.size() - 1;
		int curr = 0;
		while (curr <= pSecond)
		{
			if (nums[curr] == 0)
			{
				swap(nums[pFirst], nums[curr]);
				pFirst++;
				curr++;
				continue;
			}
			if (nums[curr] == 1)
			{
				curr++;
				continue;
			}
			if (nums[curr] == 2)
			{
				swap(nums[pSecond], nums[curr]);
				pSecond--;//这里的curr不能再加了
				continue;
			}
		}
	}
	void swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
};