#include<vector>
using namespace std;
class Solution {
public:

	int count = 0;
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n));
		int start = 0; //�����Ͻǿ�ʼ���ɾ���
		while (n > 2 * start)
		{
			fill(n, start, matrix);
			++start;
		}
		return matrix;
	}
	void fill(int n, int start, vector<vector<int>>& matrix)
	{
		//����һ��
		int endX = n - start - 1;
		int endY = n - start - 1;
		for (int i = start; i <= endX; ++i)
			matrix[start][i] = ++count;
		//Ҫ��Ҫ���������
		if (start < endY)
		{
			for (int i = start + 1; i <= endY; ++i)
				matrix[i][endX] = ++count;
			//Ҫ��Ҫ������һ��
			if (start < endX)
			{
				for (int i = endX - 1; i >= start; --i)
				{
					matrix[endY][i] = ++count;
				}
				//Ҫ��Ҫ�������ߵ���
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