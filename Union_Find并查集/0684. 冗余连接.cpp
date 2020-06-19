//使用BFS，根据入度信息来判断环，并且将需要删除的边返回
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        queue<int> Q;
        int n = edges.size();
        vector<int> indegree(n + 1, 0);
        vector<vector<int>> adjacenyMatrix(n + 1);
        //建立入度表，以及邻接矩阵
        for (int i = 0; i <= n - 1; ++i)
        {
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
            adjacenyMatrix[edges[i][0]].push_back(edges[i][1]);
            adjacenyMatrix[edges[i][1]].push_back(edges[i][0]);
        }

        //进行BFS搜索
        //找到入度为1的点，将其删除
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
            indegree[temp] = -1;  //表示将该节点删除
            for (int i = 0; i < adjacenyMatrix[temp].size(); ++i)
            {
                indegree[adjacenyMatrix[temp][i]]--;   //与之相邻的顶点入度减1
                if (indegree[adjacenyMatrix[temp][i]] == 1)
                    Q.push(adjacenyMatrix[temp][i]);
            }
        }
        //寻找入度为2的节点，把它加入到一个set中，目的是为了更快速地找到这条边
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