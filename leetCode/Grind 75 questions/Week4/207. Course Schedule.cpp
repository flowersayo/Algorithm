class Solution
{
public:
    vector<bool> visited;
    vector<vector<int>> graph;

    bool isCyclic(int n, vector<bool> recStack)
    {

        visited[n] = true; // 방문 체크
        recStack[n] = true;

        for (int i = 0; i < graph[n].size(); i++)
        {

            if (recStack[graph[n][i]])
            {
                return true;
            }

            recStack[graph[n][i]] = true;

            if (!visited[graph[n][i]] && isCyclic(graph[n][i], recStack))
            { // 사이클 판단
                return true;
            }

            recStack[graph[n][i]] = false;
        }

        recStack[n] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        graph.assign(numCourses + 1, vector<int>(0));

        visited.assign(numCourses + 1, false);
        vector<bool> recStack(numCourses + 1, false);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i] && isCyclic(i, recStack))
            {
                return false;
            }
        }

        return true;
    }
};