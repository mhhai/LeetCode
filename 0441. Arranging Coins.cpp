//��һԪ���η�����
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
//Ϊ�˱���Խ�磬���԰�8�����
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