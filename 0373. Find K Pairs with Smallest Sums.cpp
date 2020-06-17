//利用大顶堆
//最主要的还是大顶堆是按照什么顺序排序的
class Solution {
public:
    //使用仿函数作为排序准则
    class comp
    {
    public:
        bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
            return a.first + a.second < b.first + b.second;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int size = min(m * n, k);
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> Q;  //Q是一个大顶堆
        //使用双重for循环将不同对的数字加入堆中
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (Q.size() < size)
                    Q.push(make_pair(nums1[i], nums2[j]));
                else if (nums1[i] + nums2[j] < Q.top().first + Q.top().second)
                {
                    Q.pop();
                    Q.push(make_pair(nums1[i], nums2[j]));
                }
            }
        //将Q中的元素加入到res中
        vector<vector<int>> res;
        while (!Q.empty())
        {
            res.push_back({ Q.top().first, Q.top().second });
            Q.pop();
        }
        return res;
    }
};