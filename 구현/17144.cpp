#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, r;

// 북 동 남 서
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

typedef pair<int, int> ci;

vector<ci> air_purer; // 공기 청정기 위치

int sequence[2][4] = {{0, 1, 2, 3}, {2, 1, 0, 3}};

// [0] 반시계방향 : 북 동 남 서
// [1] 시계방향 : 남 동 북 서

vector<vector<int>> board;

void spread(int r_size, int c_size)
{

    vector<vector<int>> temp(r_size, vector<int>(c_size, 0)); // 확산될 양 저장해놓을 벡터

    for (int r = 0; r < r_size; r++)
    {
        for (int c = 0; c < c_size; c++)
        {
            if (board[r][c] < 5)
            {
                continue;
            }

            int dispersing_quantity = board[r][c] / 5;

            // 4방향 전파
            for (int d = 0; d < 4; d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= r_size || nc < 0 || nc >= c_size ||
                    (nr == air_purer[0].first && nc == air_purer[0].second) || (nr == air_purer[1].first && nc == air_purer[1].second))
                {
                    continue;
                }

                temp[nr][nc] += dispersing_quantity;
                board[r][c] -= dispersing_quantity;
            }
        }
    }
    // 동시에 확산 진행
    for (int r = 0; r < r_size; r++)
    {
        for (int c = 0; c < c_size; c++)
        {
            board[r][c] += temp[r][c];
        }
    }
}

// (start_r,start_c) 기준 direction : 0(반시계), 1(시계) 으로 회전
void circulate(int start_r, int start_c, int direction, int r_size, int c_size)
{

    int r = start_r;
    int c = start_c;

    int k = 0; // 방향 전환 횟수

    // 어짜피 공기 청정기가 위치한 시작 지점엔 먼지가 없으므로 따로 저장해서 옮겨줄 필요 X

    while (k < 4)
    {

        // (nr,nc) => (r,c) 로 이동

        int nr = r + dr[sequence[direction][k]];
        int nc = c + dc[sequence[direction][k]];

        if (nr < 0 || nr >= r_size || nc < 0 || nc >= c_size ||
            (direction == 0 && nr > air_purer[0].first) || (direction == 1 && nr < air_purer[1].first)) // 벽에 부딪히면 or 공기 청ㅈ
        {
            k++; // 방향 전환
            continue;
        }

        board[r][c] = board[nr][nc];

        r = nr;
        c = nc;
    }

    board[start_r][start_c] = 0; // 공기 청정기가 먼지 흡입

    // 위쪽 반시계
    // (k + 1) % 4 : 마지막 움직인 방향의 반대
    board[start_r +
          dr[sequence[direction][(k + 1) % 4]]]

         [start_c + dc[sequence[direction][(k + 1) % 4]]] = board[start_r][start_c];
}
void workAirPurifier(int r, int c)
{
    circulate(air_purer[0].first, air_purer[0].second, 0, r, c);
    circulate(air_purer[1].first, air_purer[1].second, 1, r, c);
}

int getTotalDust(int r_size, int c_size)
{

    int sum = 0;
    for (int i = 0; i < r_size; i++)
    {
        for (int j = 0; j < c_size; j++)
        {

            sum += board[i][j];
        }
    }

    return sum;
}

/**
 * [미세먼지 안녕!]
 *
 * 1. 미세먼지 확산
 *    - A[i][j]/5 만큼 네방향으로 확산
 * 2. 공기청정기가 작동
 *    - 위쪽은 반시계, 아래쪽은 시계

 */
int main()
{

    int r, c, t;
    cin >> r >> c >> t;
    board.assign(r, vector<int>(c, 0));

    int x;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> x;

            if (x == -1)
            {
                air_purer.push_back({i, j});
                continue;
            }

            board[i][j] = x;
        }
    }

    while (t--)
    {

        spread(r, c);
        workAirPurifier(r, c);
    }
    cout << getTotalDust(r, c);
}