class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> col;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            col.insert(nums[i]);
            if (col.size() > 3)
                col.erase(col.begin());
        }
        if (col.size() < 3)
            return *(col.rbegin());
        return *(col.begin());
    }
};