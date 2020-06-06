//dfs
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int ret = 0;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
            {
                if (board[i][j] == 'X')
                {
                    dfs(board, i, j);
                    ret++;
                }
            }
        return ret;
    }

    void dfs(vector<vector<char>>& board, int row, int col)
    {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '.')
            return;
        board[row][col] = '.';
        dfs(board, row - 1, col);
        dfs(board, row + 1, col);
        dfs(board, row, col - 1);
        dfs(board, row, col + 1);
    }
};

//-----------------------------------------------------------------//
//利用题目性质
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int ret = 0;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
            {
                if (board[i][j] == 'X')
                {
                    if (i > 0 && board[i - 1][j] == 'X')
                        continue;
                    else if (j > 0 && board[i][j - 1] == 'X')
                        continue;
                    else
                        ret++;
                }
            }
        return ret;
    }
};