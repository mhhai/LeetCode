//��������һ��ʾ��ûͨ�������ǶԱ���һ�´𰸣������һģһ����
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        unordered_map<int, int>  col;  //��һ��int��ŵ���intervals��һ��Ԫ�ص�ֵ���ڶ�����ŵ�����index
        for (int i = 0; i < intervals.size(); ++i)
        {
            col[intervals[i][0]] = i;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> ret(n, -1);
        for (int i = 0; i < n - 1; ++i)
        {
            if (find(intervals, i) != -1)
                ret[col[intervals[i][0]]] = col[find(intervals, i)];
            else
                ret[col[intervals[i][0]]] = -1;
        }
        return ret;
    }

    int find(vector<vector<int>>& intervals, int pos)
    {
        int target = intervals[pos][1];
        int start = 0;
        int end = intervals.size() - 1;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (intervals[mid][0] == target)
                return intervals[mid][0];
            else if (intervals[mid][0] > target)
                end = mid;
            else
                start = mid + 1;
        }
        return  intervals[start][0] >= target ? intervals[start][0] : -1;
    }
};