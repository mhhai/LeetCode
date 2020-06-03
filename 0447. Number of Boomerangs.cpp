class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ret = 0;
        for (int i = 0; i < points.size(); ++i)
        {
            //每次都要初始化
            unordered_map<int, int> col; // 第一个int代表当前点距其他点的距离，第二个int代表这个距离有多少个
            for (int j = 0; j < points.size(); ++j)
            {
                if (j != i)
                    col[dist(points[i], points[j])]++;
            }
            for (auto elem : col)    //以case: [0,0] [0,1] [0,2] [1,1]这四个点为例，[1,1]为起点，可能的组合为A(3,2)
                ret += elem.second * (elem.second - 1);
        }
        return ret;
    }
    int dist(vector<int>& a, vector<int>& b)
    {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
};