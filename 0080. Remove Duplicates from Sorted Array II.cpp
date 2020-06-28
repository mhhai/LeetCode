class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int right = 1;
        int left = 1;
        int count = 1;
        int m = nums.size();
        if (m == 0)
            return 0;
        while (right < m)
        {
            if (nums[right] == nums[right - 1])
                count++;
            else
                count = 1;
            //cout << right << " " << count << endl;
            if (count <= 2)
                nums[left++] = nums[right];
            right++;
        }
        return left;
    }
};