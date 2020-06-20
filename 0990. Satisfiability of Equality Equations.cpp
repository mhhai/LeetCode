//�޻�ͼ��ÿ����ĸ��Ϊһ���ڵ�
//ÿ��������Ϊһ���ڵ�
//�ؼ��ڵ��������г�ʼ��
//����һ��set��
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
    vector<char> parent;  //��ģ��26��parent����һ������Ҫ�����ʾ��ǰ��±�ȷ���ڵ�
    vector<int> size;  //��ʼ��Ϊ0������Set����Ӧ�Ľڵ��ʼ��Ϊ1
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        unordered_set<char> S;
        for (int i = 0; i < equations.size(); ++i)
        {
            S.insert(equations[i][0]);
            S.insert(equations[i][1]);
        }            //�����ͻ�������еĽڵ㣬����������Щ�ڵ��������
        //��������
        Union uf;
        for (int i = 0; i < equations.size(); ++i)
        {
            uf.Union(equations[i][0], equations[i][3]);
        }
    }
};