//Union_Find 用来统计图中连通块的数量
//根据Find的结果进行Union，count表示未连通节点的数目
//Union一次可能会使未连通节点的数目减1，也可能不会
//朋友圈总数是未连通区域的数目
class UF
{
public:
    UF(int n)
    {
        count = n;
        size.reserve(n);
        parent.reserve(n);  //使用resize也可以
        for (int i = 0; i < n; ++i)
        {
            size[i] = 1;
            parent[i] = i;   //每个组都有唯一的一个父节点
        }
    }

    void Union(int a, int b)  //a和b表示节点，M[a][b] == 1，表明这两个节点可以连通，连通的时候该节点可能与其他节点也连通了，因此需要找一个代表，即其父节点
    {
        int parentA = Find(a);
        int parentB = Find(b);
        if (parentA == parentB)  //说明它们已经在同一组了
            return;
        //Union之前已经确定它们是可以连通的了
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
            x = parent[x];   //在这里的循环中，不断寻找改组的父节点
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