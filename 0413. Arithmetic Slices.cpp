class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3)
            return 0;
        vector<int> dp(n, 0);  //dp�д�ŵ�����i��β�ĵȲ����еĸ���
        int sum = 0;
        for (int i = 2; i < n; ++i)
        {
            if (A[i] + A[i - 2] == 2 * A[i - 1])
                dp[i] = dp[i - 1] + 1;
            sum += dp[i];
        }
        return sum;
    }
};