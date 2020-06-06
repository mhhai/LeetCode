//使用哈希表，但是最后一个示例没有通过
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0;
        int ret = 0;
        int mx = INT_MIN;
        int length;
        for (int i = 0; i < nums.size(); ++i)
            mx = max(mx, nums[i]);
        if (mx == 0)
            return 0;
        else
            length = log2(mx) + 1;
        for (int i = length; i >= 0; --i)
        {
            mask = mask | (1 << i);   //这里是第一处需要注意的地方，不能写成mask = 1 << i; 这样没有保留高位的1
            //根据mask获取前缀，将获取的前缀放在set中
            unordered_set<int> col;
            for (auto elem : nums)
                col.insert(elem & mask);
            //获取想要的最大值
            int desire = ret | (1 << i);  //这里是第二处需要注意的地方，不能写成 ret | mask
            //将每个元素与想要获取的最大值进行异或，若异或的结果在set中能够找到，说明能够获得想要的最大值
            //否则该位为0
            //a ^ desire can be found in set, assume it is b, a ^ desire = b , thus a ^ b = desire
            //说明能够获得想要的最大值
            int flag = 0;
            for (auto elem : nums)
            {
                for (auto s : col)
                {
                    if (col.find(desire ^ s) != col.end())
                    {
                        ret = desire;
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    break;
                    flag = 0;
                }
            }

        }
        return ret;
    }
};