//暴力法：
//1.对每一个柱子，在左边寻找最高的柱子，在右边寻找最高的柱子，取其较低者，然后用其减去当前柱子高度，就是该柱子的接到的雨水量
//动态规划法
//1.记录当前柱子左边以及右边的最大值，空间时间O(2N)
//2.遍历这两个数组，得到最终接雨水的数量
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
        //遍历一遍数组，寻找最大值
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