//�򵥵Ķ�̬�滮�൱���Ż�֮��ı�����
//��Ϊ��ÿһ���������������
class Solution {
public:
	int superEggDrop(int K, int N) {
		vector<vector<int>> dp(K + 1, vector<int>(N + 1, INT_MAX));
		for (int i = 0; i < N + 1; ++i)
		{
			dp[0][i] = 0;
			dp[1][i] = i;
		}
		for (int i = 0; i < K + 1; ++i)
			dp[i][0] = 0;
		//���������
		for (int k = 2; k <= K; ++k)
		{
			for (int n = 1; n <= N; ++n)
			{
				int left = 1;
				int right = n;
				//���ҵ������� <= û������ֵ
				//dp[k - 1][i - 1] <= dp[k][n - i];
				//dp[k - 1][mid - 1] <= dp[k][n - mid]
				while (left < right)
				{
					int mid = left + (right - left) / 2;
					int b = dp[k - 1][mid - 1];  //b������mid�������ˣ���Ҫ�ӵļ�������, ����
					int nb = dp[k][n - mid];  //nb��ʾ��mid����û�飬��Ҫ�ӵļ����������ݼ�
					if (b < nb)
						left = mid + 1;
					else if (b > nb)
						right = mid - 1;
					else
						left = right = mid;
				}
				dp[k][n] = min(max(dp[k - 1][left - 1], dp[k][n - left]), max(dp[k - 1][right - 1], dp[k][n - right])) + 1;
			}
		}
		return dp[K][N];
	}
};