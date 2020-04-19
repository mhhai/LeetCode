class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		if (nums.size() < k || nums.size() == 0)
			return res;
		deque<int> Q;

		for (int i = 0; i < k; ++i)
		{
			while (!Q.empty() && nums[i] >= nums[Q.back()])
				Q.pop_back();
			Q.push_back(i);
		}

		for (int i = k; i < nums.size(); ++i)
		{
			res.push_back(nums[Q.front()]);
			while (!Q.empty() && nums[i] >= nums[Q.back()])
				Q.pop_back();
			if (!Q.empty() && Q.front() <= (i - k))
				Q.pop_front();
			Q.push_back(i);
		}
		res.push_back(nums[Q.front()]);
		return res;
	}
};