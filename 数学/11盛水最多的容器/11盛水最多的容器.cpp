class Solution {
public:
	int maxArea(vector<int>& height) {
		int mArea = 0; //记录最大的面积
		int left = 0;   //左指针
		int right = height.size() - 1;  //右指针

		while (left < right)  //若left == right 面积为0
		{
			mArea = mArea < (right - left) * min(height[left], height[right]) ? (right - left) * min(height[left], height[right]) : mArea;

			if (height[left] < height[right])
				left++;
			else
				right--;
		}
		return mArea;
	}
};