//Union_Find ����ͳ��ͼ����ͨ�������
//����Find�Ľ������Union��count��ʾ��ͨ�������Ŀ
//Unionһ�ο��ܻ�ʹδ��ͨ�ڵ����Ŀ��1��Ҳ���ܲ���
//����Ȧ������δ��ͨ�������Ŀ
class UF
{
public:
    UF(int n)
    {
        count = n;
        size.reserve(n);
        parent.reserve(n);  //ʹ��resizeҲ����
        for (int i = 0; i < n; ++i)
        {
            size[i] = 1;
            parent[i] = i;   //ÿ���鶼��Ψһ��һ�����ڵ�
        }
    }

    void Union(int a, int b)  //a��b��ʾ�ڵ㣬M[a][b] == 1�������������ڵ������ͨ����ͨ��ʱ��ýڵ�����������ڵ�Ҳ��ͨ�ˣ������Ҫ��һ���������丸�ڵ�
    {
        int parentA = Find(a);
        int parentB = Find(b);
        if (parentA == parentB)  //˵�������Ѿ���ͬһ����
            return;
        //Union֮ǰ�Ѿ�ȷ�������ǿ�����ͨ����
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
        count--;
    }
    int Find(int x)
    {
        while (x != parent[x])
            x = parent[x];   //�������ѭ���У�����Ѱ�Ҹ���ĸ��ڵ�
        return x;
    }
    int cnt()
    {
        return count;
    }
private:
    int count;
    vector<int> size;
    vector<int> parent;
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        UF uf(N);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
            {
                if (M[i][j])
                {
                    uf.Union(i, j);
                }
            }
        return uf.cnt();
    }
};

//����dfs������ȫ��ͬ��������dfs
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        int res = 0;
        vector<bool> visited(N, false);
        for (int i = 0; i < N; ++i)
        {
            if (visited[i] == false)
            {
                dfs(M, i, visited);
                res++;
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& M, int row, vector<bool>& visited)
    {
        for (int j = 0; j < M[0].size(); ++j)
        {
            if (M[row][j] && visited[j] == false)
            {
                visited[j] = true;
                dfs(M, j, visited);
            }
        }
    }
};


//ʹ��bfs
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        queue<int> Q;
        vector<bool> visited(N, false);
        int res = 0;
        //���ﲻ���Ȱѽڵ�0 push��Q�У�Ҫ��forѭ����push
        for (int i = 0; i < N; ++i)
        {
            if (visited[i])
                continue;
            Q.push(i);
            visited[i] = true;
            res++;
            while (!Q.empty())
            {
                int temp = Q.front();
                Q.pop();
                for (int j = 0; j < N; ++j)
                {
                    if (visited[j] == false && M[temp][j])
                    {
                        visited[j] = true;
                        Q.push(j);
                    }
                }
            }
        }
        return res;
    }
};