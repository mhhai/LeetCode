class Solution {
public:
	bool isFind = false;
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		search(matrix, matrix.size() - 1, 0, target);
		return isFind;
	}
	void search(vector<vector<int>> matrix, int row, int col, int target)
	{
		if (row < 0 || col >= matrix[0].size())
			return;
		if (matrix[row][col] == target)
		{
			isFind = true;
			return;
		}

		if (target > matrix[row][col] && row >= 0 && col < matrix[0].size() - 1)
		{
			//search(matrix, row, ++col, target);
			//那么它一定在当前行
			for (int i = col; i < matrix[0].size(); ++i)
			{
				if (matrix[row][i] == target)
				{
					isFind = true;
					return;
				}
			}
		}
		if (target < matrix[row][col] && row > 0 && col <= matrix[0].size() - 1)
			search(matrix, --row, col, target);
	}
};