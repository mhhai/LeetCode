class Solution {
public:
    int getSum(int a, int b) {
        int lower = 0;
        unsigned int car = 0;
        while (1)
        {
            lower = a ^ b;
            car = a & b;
            if (car == 0)
                break;
            a = lower;
            b = car << 1;  //之所以这里成立，是因为进位先左移一位再异或可以得到低位正确的结果，但是高位的结果还有待确定
        }
        return lower;
    }
};