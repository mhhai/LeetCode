//ʹ�ö�̬�滮����֮ǰ���˽Ⱪ�������ص�������
class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
		for (int i = 0; i <= n; ++i)
		{
			dp[i][i] = 0;
			dp[0][i] = 0;
			dp[i][0] = 0;
		}

		//
		for (int j = 2; j <= n; ++j)   //�������  
			for (int i = j - 1; i >= 1; --i)
			{
				//��ÿ��ѭ���У��������dp[i][j]
				for (int k = i + 1; k <= j - 1; ++k)  //k��ʾ��ͬ�ķָ��
				{
					//cout << j << " " << i <<" " <<k <<endl;
					dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
				}
				//���˵������ǣ�����Ҫ��dp[i][i + 1] ��ʼ��Ϊ0
				//��i��Ϊ�ָ��
				dp[i][j] = min(dp[i][j], i + dp[i + 1][j]);
				dp[i][j] = min(dp[i][j], j + dp[i][j - 1]);
			}
		return dp[1][n];  //ע�ⷵ��ֵ
	}
};