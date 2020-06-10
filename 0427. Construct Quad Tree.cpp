/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        if (grid.empty())
            return nullptr;
        int n = grid.size();  //方阵
        Node* res = recursion(grid, 0, 0, n);
        return res;
    }
    Node* recursion(vector<vector<int>>& grid, int row, int col, int size)
    {
        bool isLeaf = true;
        int first = grid[row][col];
        for (int i = row; i < row + size; ++i)  //注意这里的下标是从row和col开始
        {
            for (int j = col; j < col + size; ++j)
            {
                if (grid[i][j] != first)
                {
                    isLeaf = false;
                    break;
                }
            }
            if (!isLeaf)
                break;
        }
        Node* res = new Node();
        if (isLeaf)
        {
            res->isLeaf = true;
            res->val = first;
        }
        else
        {
            int n = size / 2;
            res->val = 1;
            res->isLeaf = false;
            res->topLeft = recursion(grid, row, col, n);
            res->topRight = recursion(grid, row, col + n, n);
            res->bottomLeft = recursion(grid, row + n, col, n);
            res->bottomRight = recursion(grid, row + n, col + n, n);    //注意这里的起始点
        }
        return res;
    }
};