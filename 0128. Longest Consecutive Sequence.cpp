class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); ++i)
            st.insert(nums[i]);
        int maxLength = 0;
        for (auto i : st)  //i�ᱻ����һ��
        {
            if (st.find(i - 1) != st.end())  //i�ᱻ����һ��
                continue;       //������̵ģ�ûɶ��
            int temp = 1;
            while (st.find(i + 1) != st.end())  //i�ᱻ����һ��
            {
                temp++;
                i++;
            }
            maxLength = max(maxLength, temp);
        }

        return maxLength;

    }
};