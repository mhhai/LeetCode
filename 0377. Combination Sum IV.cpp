//dfs���㷨�����ҳ����п��ܵ���ϣ����ǶԱ�����˵��ֻҪ�ҵ���ϵĸ���
//��dfs�Ĺ����У��кܶ��ظ��������⣬��˿��Կ���ʹ�ö�̬�滮
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (nums.empty())
			return 0;
		//������float����double���о�����ʧ
		vector<unsigned long long> dp(target + 1, 0);   //dp[i]��ʾ��Ϊi����ϸ���

		//�жϸ������е����Լ��
		int g = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			g = gcd(g, nums[i]);
		}
		//cout << g << endl;
		if (target % g != 0)
			return 0;
		dp[0] = 1;
		for (int i = 1; i <= target; ++i)
		{
			for (int j = 0; j < nums.size(); ++j)
			{
				if (nums[j] <= i)
					//dp[i] = (dp[i] >= INT_MAX - dp[i - nums[j]]) ? INT_MAX : dp[i] + dp[i - nums[j]];
					dp[i] += dp[i - nums[j]];  //��nums[j]��ֵΪiʱ��dp[i] += dp[0]�������1
			}
		}
		return dp[target];
	}
	int gcd(int a, int b)
	{
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
};