#include <iostream>
#include <vector>

using namespace std;

int n, m;
int ans = -1;
const int NUM_OF_BLOCKS = 5;

vector<vector<int>> board;
vector<vector<bool>> visited;

// 북 남 서 동
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// ㅜ 모양 검사 ( 왼쪽 끝점 기준)
// ㅜ ㅏ ㅗ ㅓ
int exshape[4][4][2] = {
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
    {{0, 0}, {0, 1}, {-1, 1}, {1, 1}}

};

void dfs(int cnt, int sum, int r, int c)
{

    if (cnt == 4)
    {
        ans = max(ans, sum);
        return;
    }

    for (int d = 0; d < 4; d++)
    {
        int nr = r + dr[d];
        int nc = c + dc[d];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc])
        {
            continue;
        }
        visited[nr][nc] = true;
        dfs(cnt + 1, sum + board[nr][nc], nr, nc);
        visited[nr][nc] = false;
    }
}

void check_exshape(int r, int c)
{
    for (int t = 0; t < 4; t++)
    {

        int sum = 0;
        for (int i = 0; i < 4; i++)
        {
            int nr = r + exshape[t][i][0];
            int nc = c + exshape[t][i][1];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
            {
                continue;
            }
            sum += board[nr][nc];
        }
        ans = max(sum, ans);
    }
}

/**
 * [ 테트로미노 ]
 * https://www.acmicpc.net/problem/14500
 *
 * ㅜ를 제외한 나머지 4개의 모양은 길이가 4인 DFS의 탐색 모양
 * 시작점으로부터 4개의 정점을 방문하면 반드시 테트로미노 모양 중 하나에 속한다.
 *
 * ! ㅜ 는 따로 예외처리해서 검사하기
 *
 */
int main()
{

    cin >> n >> m;

    board.assign(n, vector<int>(m, 0));

    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = true;
            check_exshape(i, j);
            dfs(1, board[i][j], i, j);
            visited[i][j] = false;
        }
    }

    cout << ans;
}