//�Ż�
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K <= 0)
            return 1;
        vector<double> dp(N + W, 0);
        //��ʼ��
        for (int i = K; i <= N; ++i)
            dp[i] = 1;
        //��ʼ��������ܸ���
        double sum = min(N - K + 1, W);
        for (int j = K - 1; j >= 0; --j)
        {
            dp[j] = sum / W;
            sum += (dp[j] - dp[j + W]);
        }
        return dp[0];
    }
};