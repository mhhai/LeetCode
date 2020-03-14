#include<vector>
using namespace std;
class Solution {
public:

	int count = 0;
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n));
		int start = 0; //从左上角开始生成矩阵
		while (n > 2 * start)
		{
			fill(n, start, matrix);
			++start;
		}
		return matrix;
	}
	void fill(int n, int start, vector<vector<int>>& matrix)
	{
		//填充第一行
		int endX = n - start - 1;
		int endY = n - start - 1;
		for (int i = start; i <= endX; ++i)
			matrix[start][i] = ++count;
		//要不要填充最右列
		if (start < endY)
		{
			for (int i = start + 1; i <= endY; ++i)
				matrix[i][endX] = ++count;
			//要不要填充最后一行
			if (start < endX)
			{
				for (int i = endX - 1; i >= start; --i)
				{
					matrix[endY][i] = ++count;
				}
				//要不要填充最左边的列
				if (start + 1 < endY)
				{
					for (int i = endY - 1; i >= start + 1; --i)
					{
						matrix[i][start] = ++count;
					}
				}
			}

		}
	}
};