//分两次相加
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> col;
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < B.size(); ++j)
            {
                col[A[i] + B[j]]++;     //col[A[i] + B[j]]代表着值为A[i] + B[j]的二维元组坐标有多少
            }
        int ret = 0;
        for (int i = 0; i < C.size(); ++i)
            for (int j = 0; j < D.size(); ++j)
            {
                if (col.find(-(C[i] + D[j])) != col.end())
                {
                    ret += col[-(C[i] + D[j])];
                }
            }
        return ret;
    }
};