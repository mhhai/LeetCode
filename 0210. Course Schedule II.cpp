class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacenyMatrix(numCourses);
        vector<int> res;
        vector<int> indegree(numCourses, 0);
        for (auto i : prerequisites)
        {
            adjacenyMatrix[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        //找到入度为0的节点
        queue<int> Q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
                Q.push(i);
        }
        while (!Q.empty())
        {
            int temp = Q.front();
            indegree[temp] = -1;
            res.push_back(temp);
            Q.pop();
            for (int i = 0; i < adjacenyMatrix[temp].size(); ++i)
            {
                indegree[adjacenyMatrix[temp][i]]--;
                if (indegree[adjacenyMatrix[temp][i]] == 0)
                    Q.push(adjacenyMatrix[temp][i]);
            }
        }
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] != -1)
            {
                vector<int> temp;
                return temp;
            }
        }
        return res;
    }
};