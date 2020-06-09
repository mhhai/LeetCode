//使用记忆化递归
//一开始的想法是递归的试探回溯法，但是时间复杂度接近o(n2n)，因此需要额外的空间来存储中间结果
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0)
            return res;

        int  n = nums.size();
        vector<int> dp(n, 1);  //该dp中存放的是以当前元素作为下标，最大整除子集的规模
        vector<int> last(n, -1);  //last存放的是当前元素作为下标，前一个元素的下标，初始化时不能为0，否则可能出现不是整除的子集’
        sort(nums.begin(), nums.end());
        //还要记录最后的结尾值，不然不能找
        int end = -1;
        int mx = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i - 1; ++j)  //不能提前截至，因为有可能找不到最大的
            {
                if (nums[i] % nums[j] == 0 && dp[i] <= dp[j])
                {
                    dp[i] = dp[j] + 1;
                    last[i] = j;
                }

            }
            if (dp[i] > mx)
            {
                mx = dp[i];
                end = i;
            }
        }
        //for(auto i : last)
            //cout << i << endl;

    //cout << end << " "<< last[end] << endl;

        for (int i = end; i != -1; i = last[i])
        {
            res.insert(res.begin(), nums[i]);
        }
        return res;

    }
};