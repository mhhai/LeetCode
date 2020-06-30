//边计算前缀和，边寻找和为k的子数组
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;  //key：前缀和，value,前缀和为key的个数
        hash[0] = 1;
        int sum = 0;  //前缀和
        int res = 0;
        int m = nums.size();
        //cout << hash[1] << endl;
        for (int i = 0; i < m; ++i)
        {
            sum += nums[i];  //sum代表着[0, i]子数组之和
            //想要寻找x, 使得 sum - x == k
            res += hash[sum - k];  //之前的前缀和已经被保存了
            hash[sum]++; //注意索引应该是要+1的，但是没关系，有就行了
        }
        return res;
    }
};