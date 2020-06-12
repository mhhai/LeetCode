class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int length = primes.size();
        vector<int> uglyNumber(n, 0);
        uglyNumber[0] = 1;
        vector<int> index(length, 0);
        for (int i = 1; i < n; ++i)
        {
            int mn = INT_MAX;
            for (int j = 0; j < length; ++j)
            {
                mn = min(mn, primes[j] * uglyNumber[index[j]]);
            }
            uglyNumber[i] = mn;
            for (int j = 0; j < length; ++j)
            {
                if (mn == primes[j] * uglyNumber[index[j]])
                    index[j]++;
            }
        }
        return uglyNumber[n - 1];
    }
};