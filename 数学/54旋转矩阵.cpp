class Solution {
public:
	vector<int> res;
	vector<vector<int>> matrix;
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		this->matrix = matrix;
		if (matrix.empty())
		{
			return res;
		}
		int rows = matrix.size();
		int cols = matrix[0].size();
		//开始的左上角坐标
		int start = 0;
		//结束循环的条件
		while (rows > 2 * start && cols > 2 * start)
		{
			printCircle(rows, cols, start);
			start++;
		}
		return res;
	}
	void printCircle(int rows, int cols, int start)
	{
		//打印最上面一行
		int endX = cols - start - 1;
		int endY = rows - start - 1;
		for (int i = start; i <= endX; ++i)
		{
			res.push_back(matrix[start][i]);
		}
		//判断是否要进行第二步
		if (start < endY)
		{
			//打印最右边一列
			for (int i = start + 1; i < rows - start; ++i)
			{
				res.push_back(matrix[i][endX]);
			}
			//判断是否要打印最后一行
			if (start < endX)
			{
				//打印最后一行
				for (int i = endX - 1; i >= start; --i)
				{
					res.push_back(matrix[endY][i]);
				}
				if (start < endY - 1)
				{
					//打印最左边的一列
					for (int i = endY - 1; i > start; --i)
					{
						res.push_back(matrix[i][start]);
					}
				}
				//判断是否要打印最左边的一列

			}
		}

	}
};