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
		//��ʼ�����Ͻ�����
		int start = 0;
		//����ѭ��������
		while (rows > 2 * start && cols > 2 * start)
		{
			printCircle(rows, cols, start);
			start++;
		}
		return res;
	}
	void printCircle(int rows, int cols, int start)
	{
		//��ӡ������һ��
		int endX = cols - start - 1;
		int endY = rows - start - 1;
		for (int i = start; i <= endX; ++i)
		{
			res.push_back(matrix[start][i]);
		}
		//�ж��Ƿ�Ҫ���еڶ���
		if (start < endY)
		{
			//��ӡ���ұ�һ��
			for (int i = start + 1; i < rows - start; ++i)
			{
				res.push_back(matrix[i][endX]);
			}
			//�ж��Ƿ�Ҫ��ӡ���һ��
			if (start < endX)
			{
				//��ӡ���һ��
				for (int i = endX - 1; i >= start; --i)
				{
					res.push_back(matrix[endY][i]);
				}
				if (start < endY - 1)
				{
					//��ӡ����ߵ�һ��
					for (int i = endY - 1; i > start; --i)
					{
						res.push_back(matrix[i][start]);
					}
				}
				//�ж��Ƿ�Ҫ��ӡ����ߵ�һ��

			}
		}

	}
};