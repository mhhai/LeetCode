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
            b = car << 1;  //֮�����������������Ϊ��λ������һλ�������Եõ���λ��ȷ�Ľ�������Ǹ�λ�Ľ�����д�ȷ��
        }
        return lower;
    }
};