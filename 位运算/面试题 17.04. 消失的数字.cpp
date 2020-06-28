class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int m = nums.size();
        int res = 0;
        res ^= m;
        for (int i = 0; i < m; ++i)
            res = res ^ i ^ nums[i];
        return res;
    }
};