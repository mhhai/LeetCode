#include<vector>
#include<set>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		set<int> setRow;
		set<int> setCol;
		int rows = matrix.size();
		int cols = matrix[0].size();
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
			{
				if (matrix[i][j] == 0)
				{
					setRow.insert(i);
					setCol.insert(j);
				}
			}
		for (auto i = setRow.begin(); i != setRow.end(); ++i)
		{
			for (int j = 0; j < cols; ++j)
				matrix[*i][j] = 0;
		}
		for (auto i = setCol.begin(); i != setCol.end(); ++i)
		{
			for (int j = 0; j < rows; ++j)
				matrix[j][*i] = 0;
		}
	}
};