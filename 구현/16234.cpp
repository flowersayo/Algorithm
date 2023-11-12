#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, l, r;
vector<vector<int>> board;

// 북 동 남 서
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

typedef pair<int, int> ci;

/**
 * [인구 이동]
 * https://www.acmicpc.net/problem/16234
 *
 * 1. 연합 국가 파악하기 ( L <= 인구차이 <= R )
 *    - bfs 탐색으로 연합 국가 정보를 배열에 저장
 *    - 이제 연합 국가의 칸의 개수, 전체 인구수 총합 정보를 같이 계산한다.
 * 2. 인구 이동
 *    - 배열에 저장된 연합 국가 정보를 통해  (연합의 인구수) / (연합을 이루고 있는 칸의 개수) 만큼 초기화
 *
 *
 */

pair<int, vector<ci>> bfs(int sr, int sc, vector<vector<int>> &visited)
{

    queue<ci> q;

    visited[sr][sc] = true;
    q.push({sr, sc});

    int total_population = 0; // 연합 국가 전체 인구 수

    vector<ci> unions;

    while (!q.empty())
    {

        ci current = q.front();
        int cr = current.first;
        int cc = current.second;
        q.pop();

        total_population += board[cr][cc];
        unions.push_back({cr, cc});

        for (int d = 0; d < 4; d++)
        {
            int nr = cr + dr[d];
            int nc = cc + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc])
            {
                continue;
            }

            int diff = abs(board[cr][cc] - board[nr][nc]); // 인구 차이

            if (diff >= l && diff <= r)
            {

                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }

    return {total_population, unions};
}

void migration(int total_population, vector<ci> unions)
{

    int union_avg = total_population / unions.size();

    for (int i = 0; i < unions.size(); i++)
    {
        ci current = unions[i];
        int r = current.first;
        int c = current.second;

        board[r][c] = union_avg; // 인구 수 업데이트
    }
}
int main()
{

    cin >> n >> l >> r;

    board.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    int t = 0;
    while (true)
    {
        vector<vector<int>> visited(n, vector<int>(n, false));

        bool isThereUnion = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    pair<int, vector<ci>> result = bfs(i, j, visited); // 연합 국가 파악

                    if (result.second.size() != 1)
                    {
                        isThereUnion = true;
                        // 연합 국가 인구수 업데이트
                        migration(result.first, result.second);
                    }
                }
            }
        }

        if (!isThereUnion)
        { // 인구차가 없어 연합 국가가 없으면
            break;
        }
        t++;
    }

    cout << t;
}