class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if (matrix.size() == 0)
            return res;
        int m = matrix.size();
        int n = matrix[0].size();


        vector<vector<bool>> pacificVisited(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticVisited(m, vector<bool>(n, false));
        int pre = INT_MIN;
        for (int i = 0; i < m; ++i)
        {
            dfs(matrix, pacificVisited, i, 0, pre);
            dfs(matrix, atlanticVisited, i, n - 1, pre);
        }
        for (int i = 0; i < n; ++i)
        {
            dfs(matrix, pacificVisited, 0, i, pre);
            dfs(matrix, atlanticVisited, m - 1, i, pre);
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                //cout << pacificVisited[i][j] << " "<< atlanticVisited[i][j] <<" ";
                if (pacificVisited[i][j] && atlanticVisited[i][j])
                    res.push_back({ i, j });
            }
            // cout << endl;
        }
        return res;
    }

    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int row, int col, int pre)
    {
        //cout << row <<" " << col << endl;
        if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size() || matrix[row][col] < pre || visited[row][col])
            return;
        //cout << "a" << endl;
        visited[row][col] = true;
        dfs(matrix, visited, row - 1, col, matrix[row][col]);
        dfs(matrix, visited, row + 1, col, matrix[row][col]);
        dfs(matrix, visited, row, col - 1, matrix[row][col]);
        dfs(matrix, visited, row, col + 1, matrix[row][col]);
    }
};