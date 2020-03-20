#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool isFind = false;
	vector<vector<char>> board;
	string word;
	bool exist(vector<vector<char>>& board, string word) {
		this->board = board;
		this->word = word;
		string path = "";
		vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
		for (int row = 0; row < board.size(); ++row)
			for (int col = 0; col < board[0].size(); ++col)
			{
				path = "";
				backTrace(path, 0, row, col, used);
				if (isFind)
					break;
			}
		return isFind;
	}

	void backTrace(string& path, int i, int row, int col, vector<vector<bool>> used)
	{
		cout << row << " " << col << endl;
		cout << "path1: " << path << endl;
		if (row < board.size() && col < board[0].size() && i < word.size() && used[row][col] == false)
		{
			if (board[row][col] != word[i])
				return;
			if (board[row][col] == word[i])
			{
				path += board[row][col];
				cout << "path2: " << path << endl;
				used[row][col] = true;
				if (path == word)
				{
					isFind = true;
					return;
				}
				//ÏòÓÒËÑÑ°
				if (row < board.size() && col < board[0].size() - 1 && i < word.size() - 1)
					backTrace(path, i + 1, row, col + 1, used);
				//ÏòÏÂËÑÑ°
				if (row < board.size() - 1 && col < board[0].size() && i < word.size() - 1)
					backTrace(path, i + 1, row + 1, col, used);
				//ÏòÉÏËÑÑ°
				if (row > 0 && col < board[0].size() && i < word.size() - 1)
					backTrace(path, i + 1, row - 1, col, used);
				//Ïò×óËÑÑ°
				if (row < board.size() && col > 0 && i < word.size() - 1)
					backTrace(path, i + 1, row, col - 1, used);

				
			}
			if (!isFind)
			{
				path.pop_back();
			}
		}
	}

};

int main()
{
	vector<vector<char>> board = { {'C','A','A'}, {'A','A','A'}, {'B','C','D'} };
	string word = "AAB";
	Solution a;
	cout << a.exist(board, word) << endl;
	system("pause");

}