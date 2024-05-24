#include <vector>
#include <queue>
using namespace std;

// 상 하 좌 우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

typedef pair<int, int> ci;
vector<vector<bool>> visited;

int bfs(int sr, int sc, vector<vector<int>> &maps, int n, int m)
{

    queue<ci> q;
    q.push({sr, sc});
    visited[sr][sc] = true;

    int answer = -1;
    int level = 1; // 현재 몇단계를 탐색 중인지

    while (!q.empty() && answer == -1)
    {

        int size = q.size();

        for (int i = 0; i < size; i++)
        { // 큐 크기만큼

            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();

            if (cr == n - 1 && cc == m - 1)
            {                   // 상대팀 진영에 도착한 경우
                answer = level; // answer 가 또 다시 갱신될 가능성 없도록 while 루프 빠져나옴
                break;
            }

            for (int i = 0; i < 4; i++)
            {
                int nr = cr + dr[i];
                int nc = cc + dc[i];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc] || maps[nr][nc] == 0)
                { // 범위를 넘거나 방문을 했거나 벽이 있다면
                    continue;
                }

                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }

        level++;
    }

    return answer;
}

int solution(vector<vector<int>> maps)
{

    int n = maps.size();
    int m = maps[0].size();

    visited.assign(n, vector<bool>(m, false));
    return bfs(0, 0, maps, n, m);
}