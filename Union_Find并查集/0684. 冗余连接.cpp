//ʹ��BFS�����������Ϣ���жϻ������ҽ���Ҫɾ���ı߷���
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        queue<int> Q;
        int n = edges.size();
        vector<int> indegree(n + 1, 0);
        vector<vector<int>> adjacenyMatrix(n + 1);
        //������ȱ��Լ��ڽӾ���
        for (int i = 0; i <= n - 1; ++i)
        {
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
            adjacenyMatrix[edges[i][0]].push_back(edges[i][1]);
            adjacenyMatrix[edges[i][1]].push_back(edges[i][0]);
        }

        //����BFS����
        //�ҵ����Ϊ1�ĵ㣬����ɾ��
        for (int i = 1; i <= n; ++i)
        {
            if (indegree[i] == 1)
                Q.push(i);
        }
        //cout << "a" << endl;
        //
        while (!Q.empty())
        {
            int temp = Q.front();
            Q.pop();
            indegree[temp] = -1;  //��ʾ���ýڵ�ɾ��
            for (int i = 0; i < adjacenyMatrix[temp].size(); ++i)
            {
                indegree[adjacenyMatrix[temp][i]]--;   //��֮���ڵĶ�����ȼ�1
                if (indegree[adjacenyMatrix[temp][i]] == 1)
                    Q.push(adjacenyMatrix[temp][i]);
            }
        }
        //Ѱ�����Ϊ2�Ľڵ㣬�������뵽һ��set�У�Ŀ����Ϊ�˸����ٵ��ҵ�������
        unordered_set<int> S;
        for (int i = 1; i <= n; ++i)
        {
            if (indegree[i] == 2)
            {
                //cout << i << endl;
                S.insert(i);
            }
        }
        for (int i = n - 1; i >= 0; --i)
        {
            if (S.find(edges[i][1]) != S.end() && S.find(edges[i][0]) != S.end())
                return edges[i];
        }
        return {};
    }
};