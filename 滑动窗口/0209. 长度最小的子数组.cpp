//使用滑动窗口
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int left = 0, right = 0;
        int n = nums.size();
        int minLength = INT_MAX;
        int sum = 0;
        while (right < n)
        {
            //更新数据
            if (sum < s)
                sum += nums[right];
            while (sum >= s)
            {
                int size = right - left + 1;
                minLength = min(size, minLength);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return left == 0 ? 0 : minLength;
    }
};