//���ô󶥶�
//����Ҫ�Ļ��Ǵ󶥶��ǰ���ʲô˳�������
class Solution {
public:
    //ʹ�÷º�����Ϊ����׼��
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
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> Q;  //Q��һ���󶥶�
        //ʹ��˫��forѭ������ͬ�Ե����ּ������
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
        //��Q�е�Ԫ�ؼ��뵽res��
        vector<vector<int>> res;
        while (!Q.empty())
        {
            res.push_back({ Q.top().first, Q.top().second });
            Q.pop();
        }
        return res;
    }
};