#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int n, m;

typedef pair<int, int> ci;

// 상하좌우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// {sr,sc} => {er,ec} 거리 반환

int bfs(int sr, int sc, int er, int ec, vector<string> maps)
{

    vector<vector<int>> visited(n, vector<int>(m, -1));

    queue<ci> q;

    visited[sr][sc] = 0;
    q.push({sr, sc});

    while (!q.empty())
    {

        ci current = q.front();
        int r = current.first;
        int c = current.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc] != -1 || maps[nr][nc] == 'X')
            {
                continue;
            }

            visited[nr][nc] = visited[r][c] + 1; // 거리

            if (nr == er && nc == ec)
            {
                break;
            }
            q.push({nr, nc});
        }
    }

    return visited[er][ec];
}

ci find_mark(vector<string> maps, char mark)
{

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].length(); j++)
        {
            if (maps[i][j] == mark)
            {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

int solution(vector<string> maps)
{
    int answer;

    n = maps.size();
    m = maps[0].length();

    vector<vector<int>> visited(n, vector<int>(m, false));

    ci start = find_mark(maps, 'S');
    ci lever = find_mark(maps, 'L');
    ci end = find_mark(maps, 'E');

    int start_to_lever = bfs(start.first, start.second, lever.first, lever.second, maps);
    int lever_to_end = bfs(lever.first, lever.second, end.first, end.second, maps);

    if (start_to_lever == -1 || lever_to_end == -1)
    {
        return -1;
    }
    answer = start_to_lever + lever_to_end;

    return answer;
}