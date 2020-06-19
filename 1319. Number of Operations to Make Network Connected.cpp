class UF
{
public:
    UF(int n)
    {
        parent.reserve(n);
        size.reserve(n);
        count = n;
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    bool Union(int a, int b)
    {
        int parentA = Find(a);
        int parentB = Find(b);
        if (parentA == parentB)
            return false;   //��������һ������
        if (size[parentA] < size[parentB])
        {
            parent[parentA] = parent[parentB];
            size[parentB] += size[parentA];
        }
        else
        {
            parent[parentB] = parent[parentA];
            size[parentA] += size[parentB];
        }
        count--;
        return true;  //��ʾ�����������
    }

    int Find(int a)
    {
        while (a != parent[a])
        {
            //parent[a] = parent[parent[a]];
            a = parent[a];
        }
        return a;
    }
    int cnt()
    {
        return count;
    }
private:
    vector<int> parent;
    vector<int> size;
    int count;

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int num = connections.size();  //��������
        UF uf(n);
        int remain = 0;
        for (int i = 0; i < num; ++i)
        {
            if (!uf.Union(connections[i][0], connections[i][1]))
                remain++;
        }
        if (remain < uf.cnt() - 1)  //uf.cnt() - 1������Ҫ�ĵ�����
            return -1;
        return uf.cnt() - 1;
    }
};