//ʹ�ü��仯�ݹ�
//һ��ʼ���뷨�ǵݹ����̽���ݷ�������ʱ�临�ӶȽӽ�o(n2n)�������Ҫ����Ŀռ����洢�м���
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0)
            return res;

        int  n = nums.size();
        vector<int> dp(n, 1);  //��dp�д�ŵ����Ե�ǰԪ����Ϊ�±꣬��������Ӽ��Ĺ�ģ
        vector<int> last(n, -1);  //last��ŵ��ǵ�ǰԪ����Ϊ�±꣬ǰһ��Ԫ�ص��±꣬��ʼ��ʱ����Ϊ0��������ܳ��ֲ����������Ӽ���
        sort(nums.begin(), nums.end());
        //��Ҫ��¼���Ľ�βֵ����Ȼ������
        int end = -1;
        int mx = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i - 1; ++j)  //������ǰ��������Ϊ�п����Ҳ�������
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