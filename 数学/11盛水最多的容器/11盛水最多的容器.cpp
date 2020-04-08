class Solution {
public:
	int maxArea(vector<int>& height) {
		int mArea = 0; //��¼�������
		int left = 0;   //��ָ��
		int right = height.size() - 1;  //��ָ��

		while (left < right)  //��left == right ���Ϊ0
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