//使用快慢指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int slow = 1;
        int fast = 1;
        int m = nums.size();
        while (fast < m)
        {
            if (nums[fast] == nums[fast - 1])
                fast++;
            else
            {
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }
        return slow;
    }
};