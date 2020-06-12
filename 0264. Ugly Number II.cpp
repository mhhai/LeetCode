class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNum(n, 0);
        uglyNum[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; ++i)
        {
            uglyNum[i] = minThress(uglyNum[i2] * 2, uglyNum[i3] * 3, uglyNum[i5] * 5);  //i2指向的是乘以2大于当前最大丑数的最大元素的下标
            //cout << uglyNum[i] << endl;
            if (uglyNum[i] == uglyNum[i2] * 2)   //获得当前元素乘以2的丑数，因此i2右移，以获得下一个可能的丑数
                i2++;
            if (uglyNum[i] == uglyNum[i3] * 3)
                i3++;
            if (uglyNum[i] == uglyNum[i5] * 5)
                i5++;
        }
        return uglyNum[n - 1];
    }
    int minThress(int a, int b, int c)
    {
        int res = min(a, b);
        res = min(res, c);
        return res;
    }
};