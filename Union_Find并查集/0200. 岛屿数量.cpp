//使用DFS + 标记
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    res++;
                }
            }
        return res;
    }
    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0')
            return;
        grid[row][col] = '0';
        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }
};

//
//使用BFS
//Queue里面放的是坐标
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        queue<pair<int, int>> Q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '0')
                    continue;
                res++;
                Q.push({ i, j });
                while (!Q.empty())
                {

                    int row = Q.front().first;
                    int col = Q.front().second;
                    Q.pop();
                    //cout << row << " " << col <<endl;
                    grid[row][col] = '0';
                    if (row > 0 && grid[row - 1][col] == '1')
                    {
                        Q.push({ row - 1, col });
                        grid[row - 1][col] = '0';
                    }
                    if (col > 0 && grid[row][col - 1] == '1')
                    {
                        Q.push({ row, col - 1 });
                        grid[row][col - 1] = '0';
                    }
                    if (row < m - 1 && grid[row + 1][col] == '1')
                    {
                        Q.push({ row + 1, col });
                        grid[row + 1][col] = '0';
                    }
                    if (col < n - 1 && grid[row][col + 1] == '1')
                    {
                        Q.push({ row, col + 1 });
                        grid[row][col + 1] = '0';
                    }
                }
            }
        return res;
    }
};

//
//并查集
class UF
{
public:
    UF(vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        count = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {

                    parent.push_back(i * n + j);  //这个值应该和下标相等，这一点对于parent非常重要
                    ++count;  //初始每个1都是连通区域
                }
                else
                    parent.push_back(-1);
                size.push_back(0);
            }
    }

    void Union(int a, int b)
    {
        int parentA = Find(a);
        int parentB = Find(b);
        if (parentA == parentB)
            return;
        if (size[parentA] < size[parentB])
        {
            parent[parentA] = parentB;
            size[parentB] += size[parentA];
        }
        else
        {
            parent[parentB] = parentA;
            size[parentA] += size[parentB];
        }
        count--; //连通区域减1
    }

    int Find(int a)
    {
        while (parent[a] != a)
        {
            a = parent[a];
            //parent[a] = parent[parent[a]];
        }
        return a;
    }

    int cnt()
    {
        return count;
    }
private:
    int count;
    vector<int> parent;
    vector<int> size;

};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        UF uf(grid);
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    if (i > 0 && grid[i - 1][j] == '1')
                        uf.Union(i * n + j, (i - 1) * n + j);
                    if (j > 0 && grid[i][j - 1] == '1')
                        uf.Union(i * n + j, i * n + j - 1);
                    if (i < m - 1 && grid[i + 1][j] == '1')
                        uf.Union(i * n + j, (i + 1) * n + j);
                    if (j < n - 1 && grid[i][j + 1] == '1')
                        uf.Union(i * n + j, i * n + j + 1);
                }
            }
        return uf.cnt();
    }
};