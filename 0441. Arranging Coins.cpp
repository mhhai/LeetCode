//求一元二次方程组
/*
class Solution {
public:
    int arrangeCoins(int n) {
        if(n <= 0)
            return 0;
        int ret = 0;
        ret = (int)((sqrt((long long)(8) * n + 1) - 1) * 0.5);
        return ret;
    }
};
*/
//为了避免越界，可以把8提出来
class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 0)
            return 0;
        int ret = 0;
        ret = (int)((sqrt(8) * sqrt(n + 1.0 / 8) - 1) * 0.5);
        return ret;
    }
};