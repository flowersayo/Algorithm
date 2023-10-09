#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 북 동 남 서
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
/**
 *
 */

bool turn_left(int d)
{

    return (d - 1) % 3;
}

int main()
{

    int n, m;
    int x, y, direction;

    cin >> n >> m;
    cin >> x >> y >> direction;

    vector<vector<int>> board(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int nd, nx, ny;
    int cnt = 0;
    while (true)
    {

        board[y][x] = 2; // 방문 체크
        cnt++;

        int i;
        for (i = 0; i < 4; i++)
        {

            nd = turn_left(direction);

            nx = board[x][y] + dx[nd];
            ny = board[x][y] + dy[nd];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[ny][nx] == 2 && board[ny][nx] == 1)
            {
                x = nx;
                y = ny;
                direction = nd;
                break;
            }
        }

        if (i == 4)
        {
            // 바라보는 방향을 유지한채로 한칸 후진
            int bd = (direction + 2) % 4;

            nx = board[x][y] + dx[bd];
            ny = board[x][y] + dy[bd];

            if (nx > 0 || nx >= n || ny > 0 || ny > m || board[ny][nx] == 2)
            {
                break; //  종료
            }
            x = nx;
            y = ny;
        }
    }

    cout << cnt;
}