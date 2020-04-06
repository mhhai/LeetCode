class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		vector<int> result;
		for (int i = 0; i < nums.size(); ++i)
		{
			cout << i << endl;
			int temp = target - nums[i];
			if (hash.find(temp) != hash.end())
			{
				result.push_back(i);
				result.push_back(hash[temp]);
				break;
			}
			else
			{
				//nums[0] = 2为key, 即已有元素值，由于 i = 0 value,即为下标
				hash[nums[i]] = i;
			}
		}
		return result;
	}
};