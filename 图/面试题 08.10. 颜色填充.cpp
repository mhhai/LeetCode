//使用dfs
//要使用一个visited数组
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.empty())
            return image;
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        //cout << "a: " << image.size() << " " << image[0].size() << endl;
        dfs(image, sr, sc, image[sr][sc], newColor, visited);
        return image;
    }

    void dfs(vector<vector<int>>& image, int row, int col, int target, int newColor, vector<vector<bool>>& visited)
    {

        if (row < 0 || col < 0 || row >= image.size() || col >= image[0].size() || visited[row][col] || image[row][col] != target)
            return;
        //cout << row << " " << col << endl;
        //否则将该位置进行填充
        image[row][col] = newColor;
        visited[row][col] = true;
        dfs(image, row + 1, col, target, newColor, visited);
        dfs(image, row - 1, col, target, newColor, visited);
        dfs(image, row, col + 1, target, newColor, visited);
        dfs(image, row, col - 1, target, newColor, visited);
    }
};