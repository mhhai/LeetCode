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
        //�ݹ��
        if (n == 0)
        {
            return;
        }
        //�ҵ����ֵ
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
        //��תһ��
        reverse(A, maxIndex);
        reverse(A, n);
        //�������ŵ�res��
        res.push_back(maxIndex + 1);
        res.push_back(n + 1);
        //for(int i = 0; i < A.size(); ++i)
          //  cout << A[i] << " ";
        //cout << endl;
        recurse(A, n - 1);
    }
    void reverse(vector<int>& A, int pos)  //�ú���������λ��i���ļ�����з�ת
    {
        int i = 0;  // ��ʹ�ǵݹ�Ҳ�Ǵ�λ��0��ʼ��ת
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