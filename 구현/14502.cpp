#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int ans = -1;
const int NUM_OF_WALL = 3;
int n, m;

// 북 동 남 서
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<vector<bool>> visited;

// (r,c) : 바이러스 진원지로부터 퍼뜨리기
void spread(int r, int c, vector<vector<int>> &board)
{

    if (visited[r][c])
    {
        return;
    }

    visited[r][c] = true;
    board[r][c] = 2;

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m || board[nr][nc] != 0)
        {
            continue;
        }
        spread(nr, nc, board);
    }
}

int calcSafetyZone(vector<vector<int>> &board)
{

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
            {
                count++;
            }
        }
    }
    return count;
}
void buildWall(int cnt, int r, int c, vector<vector<int>> board)
{

    if (cnt == NUM_OF_WALL)
    {
        visited.assign(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 2 && !visited[i][j])
                {
                    spread(i, j, board);
                }
            }
        }

        int count = calcSafetyZone(board);
        ans = max(ans, count);
        return;
    }

    // 벽 하나 세우기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (board[i][j] == 0)
            { // 빈칸일때에만 벽 세우기
                board[i][j] = 1;
                buildWall(cnt + 1, i, j, board);
                board[i][j] = 0; // 원상 복구
            }
        }
    }
}

/**
 * [연구소]
 * https://www.acmicpc.net/problem/14502
 *
 *
 * 1. 벽 3개 세우기
 * -> dfs 탐색
 *
 * 2. 바이러스 퍼뜨리고 안전 영역 크기 구하기
 *
 */
int main()
{

    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    buildWall(0, 0, 0, board);

    cout << ans;
}