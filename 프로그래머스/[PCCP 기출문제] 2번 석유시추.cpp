#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 만나는 석유 지점을 포함하는 bfs 탐색

typedef pair<int, int> ci;

// 북 동 남 서
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<ci> bfs(int n, int m, vector<vector<int>> &land, int sr, int sc, vector<vector<bool>> &visited)
{

    vector<ci> coords; // 방문한 좌표 목록

    queue<ci> q;

    int cnt = 0;
    q.push({sr, sc});
    visited[sr][sc] = true;

    while (!q.empty())
    {

        ci current = q.front();
        int r = current.first;
        int c = current.second;
        cnt++;
        coords.push_back({r, c});
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m || land[nr][nc] == 0 || visited[nr][nc])
            {
                continue;
            }
            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }

    return coords;
}

void mark_oil_size(int size, vector<ci> coords, vector<vector<int>> &dp)
{

    for (auto coord : coords)
    {

        int r = coord.first;
        int c = coord.second;

        dp[r][c] = size;
    }
}

int solution(vector<vector<int>> land)
{

    int answer = -1;

    int n = land.size();
    int m = land[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    // j : 어떤 열을 선택할지
    for (int j = 0; j < land[0].size(); j++)
    {

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        // dp[i][j]: (i,j) 를 포함하는 석유의 전체 크기

        int amount_of_oil = 0; // 시추관이 뽑을 수 있는 오일 수
        for (int i = 0; i < land.size(); i++)
        {

            if (visited[i][j] || land[i][j] == 0)
            {
                continue;
            }

            if (dp[i][j])
            { // 이미 (i,j) 를 포함하는 영역의 오일크기가 구해져 있으면
                amount_of_oil += dp[i][j];
                continue;
            }

            vector<ci> coords = bfs(n, m, land, i, j, visited);
            int size_of_area = coords.size();
            mark_oil_size(size_of_area, coords, dp);
            // cout<<i<<j<<"에서 dfs호출!"<<"size_of_area"<<size_of_area;
            amount_of_oil += size_of_area;
        }

        answer = max(answer, amount_of_oil);
    }
    return answer;
}