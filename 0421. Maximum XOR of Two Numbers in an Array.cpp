//ʹ�ù�ϣ���������һ��ʾ��û��ͨ��
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
            mask = mask | (1 << i);   //�����ǵ�һ����Ҫע��ĵط�������д��mask = 1 << i; ����û�б�����λ��1
            //����mask��ȡǰ׺������ȡ��ǰ׺����set��
            unordered_set<int> col;
            for (auto elem : nums)
                col.insert(elem & mask);
            //��ȡ��Ҫ�����ֵ
            int desire = ret | (1 << i);  //�����ǵڶ�����Ҫע��ĵط�������д�� ret | mask
            //��ÿ��Ԫ������Ҫ��ȡ�����ֵ������������Ľ����set���ܹ��ҵ���˵���ܹ������Ҫ�����ֵ
            //�����λΪ0
            //a ^ desire can be found in set, assume it is b, a ^ desire = b , thus a ^ b = desire
            //˵���ܹ������Ҫ�����ֵ
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