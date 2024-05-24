#include <vector>
#include <queue>
using namespace std;

// 상 하 좌 우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

typedef pair<int, int> ci;
vector<vector<int>> visited;

int bfs(int sr, int sc, vector<vector<int>> &maps, int n, int m)
{

    queue<ci> q;
    q.push({sr, sc});
    visited[sr][sc] = 1;

    while (!q.empty())
    {

        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc] != -1 || maps[nr][nc] == 0)
            { // 범위를 넘거나 방문을 했거나 벽이 있다면
                continue;
            }

            q.push({nr, nc});
            visited[nr][nc] = visited[cr][cc] + 1;
        }
    }

    return visited[n - 1][m - 1];
}

int solution(vector<vector<int>> maps)
{

    int n = maps.size();
    int m = maps[0].size();

    visited.assign(n, vector<int>(m, -1));
    return bfs(0, 0, maps, n, m);
}