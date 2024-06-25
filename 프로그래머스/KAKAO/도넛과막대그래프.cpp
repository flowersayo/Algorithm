#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

typedef pair<int, int> ci;

map<int, vector<int>> graphs; // 정점 범위가 1,000,000으로 커서 메모리 절약을 위해 map으로 선언

map<int, bool> visited; // 특정 정점을 방문했는지 여부

int getType(int edge_cnt, int vertex_cnt, int start, int last)
{

    if (edge_cnt == vertex_cnt)
    {
        return 1; // 도넛 모양
    }
    else if (edge_cnt + 1 == vertex_cnt)
    {
        return 2; // 막대 모양
    }
    else if (edge_cnt == vertex_cnt + 1)
    {
        return 3; // 8자 모양
    }

    return 0;
}
// start 에서 출발해서 어떤 모양의 그래프인지 반환
int bfs(int start)
{

    queue<int> q;

    int edge_cnt = 0;
    int vertex_cnt = 0;
    int last = -1;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {

        int current = q.front();
        vertex_cnt++;

        q.pop();

        for (auto adj_node : graphs[current])
        {

            edge_cnt++;

            if (visited[adj_node])
            { //
                continue;
            }

            q.push(adj_node);
            visited[adj_node] = true;
        }
    }

    return getType(edge_cnt, vertex_cnt, start, last);
}

// 추가된 정점 찾기
int findAddedVertex(map<int, vector<int>> graphs, map<int, int> indegree)
{

    for (auto iter = graphs.begin(); iter != graphs.end(); iter++)
    {

        if (iter->second.size() >= 2 && indegree[iter->first] == 0)
        { // 나가는 정점이 2개 이상인데, 들어오는 정점이 0개이면
            return iter->first;
        }
    }

    return -1;
}
vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer(4, 0);

    map<int, int> indegree;

    // graphs[a] : 정점 a와 연결되어 있는 노드들
    // map : 정점의 범위가 넓은데, 정점은 얼마 없을 때 메모리를 효율적으로 사용할 수 있도록 도와줌.

    for (auto edge : edges)
    {
        graphs[edge[0]].push_back(edge[1]); // 단방향 그래프
        indegree[edge[1]]++;
    }

    int v = findAddedVertex(graphs, indegree);
    answer[0] = v;

    // v 에서 연결된 그래프들 하나씩 방문
    for (auto start_node : graphs[v])
    {

        int type = bfs(start_node);
        answer[type]++;
    }

    return answer;
}