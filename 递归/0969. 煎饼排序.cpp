//
class Solution {
public:
    vector<int> res;
    vector<int> pancakeSort(vector<int>& A) {
        int m = A.size() - 1;
        recurse(A, m);
        return res;
    }
    void recurse(vector<int>& A, int n)
    {
        //递归基
        if (n == 0)
        {
            return;
        }
        //找到最大值
        int maxIndex = 0;
        int mx = A[0];
        for (int i = 0; i <= n; ++i)
        {
            if (A[i] > mx)
            {
                mx = A[i];
                maxIndex = i;
            }
        }
        //翻转一次
        reverse(A, maxIndex);
        reverse(A, n);
        //将索引放到res中
        res.push_back(maxIndex + 1);
        res.push_back(n + 1);
        //for(int i = 0; i < A.size(); ++i)
          //  cout << A[i] << " ";
        //cout << endl;
        recurse(A, n - 1);
    }
    void reverse(vector<int>& A, int pos)  //该函数用来将位置i处的煎饼进行翻转
    {
        int i = 0;  // 即使是递归也是从位置0开始翻转
        while (i < pos)
        {
            int temp = A[i];
            A[i] = A[pos];
            A[pos] = temp;
            pos--;
            i++;
        }
    }
};