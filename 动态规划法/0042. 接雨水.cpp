//��������
//1.��ÿһ�����ӣ������Ѱ����ߵ����ӣ����ұ�Ѱ����ߵ����ӣ�ȡ��ϵ��ߣ�Ȼ�������ȥ��ǰ���Ӹ߶ȣ����Ǹ����ӵĽӵ�����ˮ��
//��̬�滮��
//1.��¼��ǰ��������Լ��ұߵ����ֵ���ռ�ʱ��O(2N)
//2.�������������飬�õ����ս���ˮ������
class Solution {
public:
    int trap(vector<int>& height) {
        int m = height.size();
        if (m <= 2)
            return 0;
        vector<int> leftMax(m, 0);
        vector<int> rightMax(m, 0);
        int mx = INT_MIN;
        for (int i = 1; i < m; ++i)
        {
            leftMax[i] = max(mx, height[i - 1]);
            mx = leftMax[i];
            //cout << leftMax[i] << " ";
        }
        cout << endl;
        mx = INT_MIN;
        for (int i = m - 2; i >= 0; --i)
        {
            rightMax[i] = max(mx, height[i + 1]);
            mx = rightMax[i];
            //cout << rightMax[i] << " ";
        }
        cout << endl;
        //����һ�����飬Ѱ�����ֵ
        int res = 0;
        for (int i = 1; i < m - 1; ++i)
        {
            int temp = min(leftMax[i], rightMax[i]) - height[i];
            if (temp > 0)
                res += temp;
        }
        return res;
    }
};