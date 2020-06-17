// π”√¥Û∂•∂—
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		if (matrix.empty() || k <= 0)
			return 0;
		priority_queue<int> Q;
		for (int i = 0; i < matrix.size(); ++i)
			for (int j = 0; j < matrix[0].size(); ++j)
			{
				if (Q.size() < k)
					Q.push(matrix[i][j]);
				else
				{
					if (matrix[i][j] < Q.top())
					{
						Q.pop();
						Q.push(matrix[i][j]);
					}
				}
			}
		return Q.top();
	}
};