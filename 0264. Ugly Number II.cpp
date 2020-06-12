class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNum(n, 0);
        uglyNum[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; ++i)
        {
            uglyNum[i] = minThress(uglyNum[i2] * 2, uglyNum[i3] * 3, uglyNum[i5] * 5);  //i2ָ����ǳ���2���ڵ�ǰ�����������Ԫ�ص��±�
            //cout << uglyNum[i] << endl;
            if (uglyNum[i] == uglyNum[i2] * 2)   //��õ�ǰԪ�س���2�ĳ��������i2���ƣ��Ի����һ�����ܵĳ���
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