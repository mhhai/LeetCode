//��Ȩ�صĹ�ϣ��
//֮����x / x = -1.0 ��Ϊ����ʽ�ϵ�ͳһ
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
        pair<string, double> parentA = Find(a);  //���ص���a / root(a)��ֵ
        pair<string, double> parentB = Find(b);
        if (parentA.first == "" || parentB.first == "")
            return;
        if (parentA == parentB)//�Ѿ��������ˣ�û��Ҫ������
            return;
        //���ﲻʹ�ð��Ⱥϲ�
        //����������������ʱ�򣬲�֪��ʹ��r0 / r1�� ����r1 / r0
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
            res *= weight[a];  //������root֮���Ȩ��
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
    unordered_map<string, string> parent; // ����ʹ�õ��ǹ�ϣ��, �ڶ����ڵ��ǵ�һ���ڵ�ĸ��׽ڵ�
    unordered_map<string, double> weight; //������ǰ�ڵ���Ը��ڵ��ֵ
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
        //����ÿһ��queries�������
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