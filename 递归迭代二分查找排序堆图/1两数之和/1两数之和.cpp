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
				//nums[0] = 2Ϊkey, ������Ԫ��ֵ������ i = 0 value,��Ϊ�±�
				hash[nums[i]] = i;
			}
		}
		return result;
	}
};