//无环图，每个字母作为一个节点
//每个数字作为一个节点
//关键节点怎样进行初始化
//放在一个set中
class UF
{
public:
    UF(unordered_set<char> S)
    {
        parent.reserve(26);
        size.reserve(26)
            for (int i = 0; i < 26; ++i)
            {
                parent[i] = 'a' + i;
                size[i] = 0;
            }
        for (auto i : S)
        {
            size[i - 'a'] = 1;
        }
    }

    void Union(int a, int b)
    {
        int parentA = Find(a);
        int parentB = Find(b);
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
            x = parent[x];
        return x;
    }
private:
    int count;
    vector<char> parent;  //规模是26，parent数组一个很重要的性质就是按下标确定节点
    vector<int> size;  //初始化为0，根据Set将对应的节点初始化为1
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        unordered_set<char> S;
        for (int i = 0; i < equations.size(); ++i)
        {
            S.insert(equations[i][0]);
            S.insert(equations[i][1]);
        }            //这样就获得了所有的节点，接下来对这些节点进行连接
        //进行连接
        Union uf;
        for (int i = 0; i < equations.size(); ++i)
        {
            uf.Union(equations[i][0], equations[i][3]);
        }
    }
};