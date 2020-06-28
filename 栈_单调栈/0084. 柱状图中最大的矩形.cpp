//枚举高
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int m = heights.size();
        for (int i = 0; i < m; ++i)
        {
            int high = heights[i];
            int left = i, right = i;
            while (left > 0 && heights[left - 1] >= high)
                left--;
            while (right < m - 1 && heights[right + 1] >= high)
                right++;
            res = max(res, (right - left + 1) * high);
        }
        return res;
    }
};

//枚举宽
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        int ans = INT_MIN;
        int m = heights.size();
        for (int left = 0; left < m; ++left)
        {
            int min_left = left;
            for (int right = left; right < m; ++right)
            {
                min_left = heights[min_left] < heights[right] ? min_left : right;  //最短的柱子所在的下标 
                ans = max(ans, (right - left + 1) * heights[min_left]);
            }
        }
        return ans;
    }
};
