#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	vector<vector<string>> res;
	vector<vector<string>> solveNQueens(int n) {
		vector<string> board(n, string(n, '.'));
		backTrace(board, 0);
		return res;
	}

	void backTrace(vector<string> board, int row)
	{
		cout << row << endl;
		if (row == board.size())
		{
			res.push_back(board);
			return;
		}

		//在每一列中做选择
		for (int i = 0; i < board.size(); ++i)
		{
			//在board上选择第row行，第i列放置Q是否可以
			if (!isValid(board, row, i))
			{
				continue;
			}
			//可以做选择了
			board[row][i] = 'Q';
			backTrace(board, row + 1);
			//撤销选择
			board[row][i] = '.';
		}
	}
	//该函数的含义是在board的第row行，第i列放置Q是否可行
	bool isValid(vector<string> board, int row, int col)
	{
		cout << "col: " << col << endl;
		//看该列有没有'Q'
		//该行不可有'Q',因为有'Q'的话会进入到下一行，回到该行时，Q已经被撤销
		for (int i = 0; i < board.size(); ++i)
		{
			if (board[i][col] == 'Q')
				return false;
		}
		cout << "a" << endl;
		//看左下角有没有Q
		for (int i = row - 1, j = col - 1; i >= 0&& j >= 0; --i, --j)
		{
			if (board[i][j] == 'Q')
				return false;
		}
		cout << "a" << endl;
		//看右下角有没有Q
		for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); --i, ++j)
		{
			cout << i << j << endl;
			if (board[i][j] == 'Q')
				return false;
		}
		cout << "a" << endl;
		cout << "a" << endl;
		cout << "a" << endl;
		return true;
	}
};

int main()
{
	int n = 4;
	Solution a;
	vector<vector<string>> res;
	res = a.solveNQueens(n);
	for (int i = 0; i < res.size(); ++i)
	{
		//cout << res[i] << endl;
	}
}