class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacenyMatrix(numCourses);
        //构建邻接矩阵
        for (auto i : prerequisites)
        {
            adjacenyMatrix[i[1]].push_back(i[0]);
        }
        vector<int> record(numCourses, 0);  //0表示节点未被访问
        for (int i = 0; i < numCourses; ++i)
        {
            if (!dfs(adjacenyMatrix, record, i))
                return false;  //有环则返回false
        }
        return true;
    }

    bool dfs(vector<vector<int>>& adjacenyMatrix, vector<int>& record, int course)
    {
        if (record[course] == 1)
            return false; //有环
        if (record[course] == 2)
            return true;
        record[course] = 1;
        for (int i = 0; i < adjacenyMatrix[course].size(); ++i)
        {
            if (!dfs(adjacenyMatrix, record, adjacenyMatrix[course][i]))
                return false;
        }
        record[course] = 2;
        return true;
    }

};


//使用BFS
//利用了有向无环图中必有一个入度为0的节点，当然也必有一个出度为0的节点
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacenyMatrix(numCourses);
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
                return false;
        }
        return true;
    }
};