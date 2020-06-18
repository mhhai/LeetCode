class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacenyMatrix(numCourses);
        //�����ڽӾ���
        for (auto i : prerequisites)
        {
            adjacenyMatrix[i[1]].push_back(i[0]);
        }
        vector<int> record(numCourses, 0);  //0��ʾ�ڵ�δ������
        for (int i = 0; i < numCourses; ++i)
        {
            if (!dfs(adjacenyMatrix, record, i))
                return false;  //�л��򷵻�false
        }
        return true;
    }

    bool dfs(vector<vector<int>>& adjacenyMatrix, vector<int>& record, int course)
    {
        if (record[course] == 1)
            return false; //�л�
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


//ʹ��BFS
//�����������޻�ͼ�б���һ�����Ϊ0�Ľڵ㣬��ȻҲ����һ������Ϊ0�Ľڵ�
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
        //�ҵ����Ϊ0�Ľڵ�
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