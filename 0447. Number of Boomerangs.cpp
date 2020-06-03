class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ret = 0;
        for (int i = 0; i < points.size(); ++i)
        {
            //ÿ�ζ�Ҫ��ʼ��
            unordered_map<int, int> col; // ��һ��int����ǰ���������ľ��룬�ڶ���int������������ж��ٸ�
            for (int j = 0; j < points.size(); ++j)
            {
                if (j != i)
                    col[dist(points[i], points[j])]++;
            }
            for (auto elem : col)    //��case: [0,0] [0,1] [0,2] [1,1]���ĸ���Ϊ����[1,1]Ϊ��㣬���ܵ����ΪA(3,2)
                ret += elem.second * (elem.second - 1);
        }
        return ret;
    }
    int dist(vector<int>& a, vector<int>& b)
    {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
};