#include <iostream>
#include <vector>

using namespace std;

// 북 동 남 서
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<vector<int>> board;
pair<int, int> coord;

void moveSpiral(int n, int k)
{
    int cr = n / 2, cc = n / 2;
    int size = 1;
    int d = 0; // 현재 움직임 방향
    int i = 1; // 현재 숫자

    board[cr][cc] = i;
    if (k == i)
    {
        coord = {cr, cc};
    }
    i++;

    while (i <= n * n)
    {
        for (int j = 0; j < 2; j++) // 두 번 방향 전환
        {
            for (int s = 0; s < size; s++)
            {
                if (i > n * n)
                {
                    return;
                }

                int nr = cr + dr[d];
                int nc = cc + dc[d];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                {
                    return;
                }

                cr = nr;
                cc = nc;

                board[cr][cc] = i;
                if (k == i)
                {
                    coord = {cr, cc};
                }
                i++;
            }
            d = (d + 1) % 4; // 방향 전환
        }

        size++; // 한 번의 전체 회전 후 사이즈 증가
    }
}

void printBoard(const vector<vector<int>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    board.assign(n, vector<int>(n, 0));
    moveSpiral(n, k);
    printBoard(board, n);

    cout << coord.first + 1 << " " << coord.second + 1 << "\n";
}
