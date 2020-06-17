class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); ++i)
            st.insert(nums[i]);
        int maxLength = 0;
        for (auto i : st)  //i会被访问一次
        {
            if (st.find(i - 1) != st.end())  //i会被访问一次
                continue;       //不是最短的，没啥用
            int temp = 1;
            while (st.find(i + 1) != st.end())  //i会被访问一次
            {
                temp++;
                i++;
            }
            maxLength = max(maxLength, temp);
        }

        return maxLength;

    }
};