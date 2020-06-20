//带权重的哈希表
//之所以x / x = -1.0 是为了形式上的统一
class UF
{
public:
    UF(vector<vector<string>> equations)
    {
        count = 0;
        for (int i = 0; i < equations.size(); ++i)
        {
            if (parent.find(equations[i][0]) == parent.end())
            {
                parent[equations[i][0]] = equations[i][0];
                weight[equations[i][0]] = 1.0;
                size[equations[i][0]] = 1;
                count++;
            }
            if (parent.find(equations[i][1]) == parent.end())
            {
                parent[equations[i][1]] = equations[i][1];
                weight[equations[i][1]] = 1.0;
                size[equations[i][1]] = 1;
                count++;
            }
        }
    }

    void Union(string a, string b, double a_b)
    {
        pair<string, double> parentA = Find(a);  //返回的是a / root(a)的值
        pair<string, double> parentB = Find(b);
        if (parentA.first == "" || parentB.first == "")
            return;
        if (parentA == parentB)//已经连接上了，没必要再连接
            return;
        //这里不使用按秩合并
        //否则再最终求结果的时候，不知道使用r0 / r1， 还是r1 / r0
        parent[parentA.first] = parentB.first;
        size[parentB.first] += size[parentA.first];
        weight[parentA.first] = 1 / parentA.second * a_b * parentB.second;
        /*
    if(size[parentA.first] < size[parentB.first])
    {
        parent[parentA.first] = parentB.first;
        size[parentB.first] += size[parentA.first];
        weight[parentA.first] = 1 / parentA.second * a_b * parentB.second;
    }
    else
    {
        parent[parentB.first] = parentA.first;
        size[parentA.first] += size[parentB.first];
        weight[parentB.first] = 1 / parentB.second * a_b * parentA.second;
    }
    */
        count--;
    }

    pair<string, double> Find(string a)
    {
        if (parent.find(a) == parent.end())
            return { "", -1.0 };
        double res = 1.0;
        while (a != parent[a])
        {
            res *= weight[a];  //更新与root之间的权重
            //weight[a] =  res;
            a = parent[a];
        }
        return { a, res };

    }

    bool isConnected(string a, string b)
    {
        while (a != parent[a])
            a = parent[a];
        while (b != parent[b])
            b = parent[b];
        return a == b;
    }
    unordered_map<string, string> parent; // 这里使用的是哈希表, 第二个节点是第一个节点的父亲节点
    unordered_map<string, double> weight; //表明当前节点除以根节点的值
    unordered_map<string, int> size;
    int count;
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        UF uf(equations);
        for (int i = 0; i < equations.size(); ++i)
        {
            uf.Union(equations[i][0], equations[i][1], values[i]);
        }
        vector<double> res;
        //对于每一个queries，求其答案
        for (int i = 0; i < queries.size(); ++i)
        {
            if (uf.parent.find(queries[i][0]) == uf.parent.end() || uf.parent.find(queries[i][1]) == uf.parent.end())
                res.push_back(-1.0);
            else if (uf.isConnected(queries[i][0], queries[i][1]))
                res.push_back(uf.Find(queries[i][0]).second / uf.Find(queries[i][1]).second);
            else
                res.push_back(-1.0);
        }
        return res;
    }
};