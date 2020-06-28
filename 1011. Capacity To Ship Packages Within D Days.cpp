//ʹ�ö��ֲ���
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int m = weights.size();
        int mx = INT_MIN;
        int sum = 0;
        for (int i = 0; i < m; ++i)
        {
            mx = max(mx, weights[i]);
            sum += weights[i];
        }
        int left = mx;
        int right = sum;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (canTra(weights, mid, D))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
    //�ڴ�������ص�����£�D�����ܷ������
    bool canTra(vector<int>& weights, int tran, int D)
    {
        int m = weights.size();
        int i = 0;
        int res = 0;    //tran�ض��Ǵ����κ�һ��weights[i]ֵ��
        while (i < m)
        {
            int temp = tran;
            while (i < m && temp - weights[i] >= 0)
            {
                temp -= weights[i];
                i++;
            }
            res++;
        }
        return res <= D;
    }
};