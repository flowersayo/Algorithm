#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, r;
vector<vector<int>> board;

// 북 동 남 서
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<int> counterClockwise = {1, 2, 3, 0}; // 동 남 서 북

void rotate(int depth) // (dpeth,depth) 에서 반시계방향으로 1회 돌려주는 함수
{

    int start = board[depth][depth];

    int sr = depth;
    int sc = depth;

    int cr = sr;
    int cc = sc;

    int direction = 0;

    while (direction < 4)
    {

        int nr = cr + dr[counterClockwise[direction]];
        int nc = cc + dc[counterClockwise[direction]];
        if (nr < depth || nr >= n - depth || nc < depth || nc >= m - depth)
        {
            direction++; // 다음 방향으로
            continue;
        }

        board[cr][cc] = board[nr][nc];

        cr = nr;
        cc = nc;
    }
    board[sr + 1][sc] = start;
}
int main()
{

    cin >> n >> m >> r;

    board.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int box_cnt = min(n, m) / 2;

    for (int i = 0; i < box_cnt; i++)
    {

        for (int j = 0; j < r; j++) // r 번 회전
        {
            rotate(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}