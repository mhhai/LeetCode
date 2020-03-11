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

		//��ÿһ������ѡ��
		for (int i = 0; i < board.size(); ++i)
		{
			//��board��ѡ���row�У���i�з���Q�Ƿ����
			if (!isValid(board, row, i))
			{
				continue;
			}
			//������ѡ����
			board[row][i] = 'Q';
			backTrace(board, row + 1);
			//����ѡ��
			board[row][i] = '.';
		}
	}
	//�ú����ĺ�������board�ĵ�row�У���i�з���Q�Ƿ����
	bool isValid(vector<string> board, int row, int col)
	{
		cout << "col: " << col << endl;
		//��������û��'Q'
		//���в�����'Q',��Ϊ��'Q'�Ļ�����뵽��һ�У��ص�����ʱ��Q�Ѿ�������
		for (int i = 0; i < board.size(); ++i)
		{
			if (board[i][col] == 'Q')
				return false;
		}
		cout << "a" << endl;
		//�����½���û��Q
		for (int i = row - 1, j = col - 1; i >= 0&& j >= 0; --i, --j)
		{
			if (board[i][j] == 'Q')
				return false;
		}
		cout << "a" << endl;
		//�����½���û��Q
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