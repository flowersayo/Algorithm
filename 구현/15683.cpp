
#include <iostream>
#include <vector>

using namespace std;

int n, m;
const int INF = 67;
int ans = INF;

typedef pair<int, int> ci;
vector<ci> cctvs;

// 북 동 남 서
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// 각 감시카메라 감시 방향
vector<vector<vector<int>>> cctv_direction_cases = {
    {}, {{0}, {1}, {2}, {3}}, {{0, 2}, {1, 3}}, {{0, 1}, {1, 2}, {2, 3}, {3, 0}}, {{1, 2, 3}, {0, 2, 3}, {0, 1, 3}, {1, 2, 0}}, {{0, 1, 2, 3}}

};

// (r,c) 에서 특정 방향으로 벽을 만나거나 범위를 벗어나기전까지 감시(방문) 체크
void mark_straight(int r, int c, int direction, vector<vector<int>> &board)
{

    int cr = r;
    int cc = c;

    while (true)
    {

        int nr = cr + dr[direction];
        int nc = cc + dc[direction];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m || board[nr][nc] == 6)
        {
            break;
        }

        cr = nr;
        cc = nc;

        if (board[cr][cc] == 0) // cctv 칸이 아니라면
        {
            board[cr][cc] = -1; // 감시 표시
        }
    }
}

// (r,c) 에서 cctv_type 의 감시영역 구하는 함수
vector<vector<int>> mark_monitored(int r, int c, vector<int> directions, vector<vector<int>> board)
{

    for (auto direction : directions)
    {
        mark_straight(r, c, direction, board);
    }

    return board; // 복제본 반환
}

int countBlind(vector<vector<int>> board)
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

void dfs(int cnt, vector<vector<int>> board) // cnt : 몇번째 cctv 인지
{

    if (cnt == cctvs.size())
    {                                  // 모든 cctv 의 방향 선택이 끝나면
        int blind = countBlind(board); // 사각지대 개수
        ans = min(ans, blind);
        return;
    }

    // cctvs[i] 번째 감시 카메라 방향 선택
    int r = cctvs[cnt].first;
    int c = cctvs[cnt].second;

    int type = board[r][c];
    vector<vector<int>> cases = cctv_direction_cases[type];

    // 감시 경우의 수 중 하나 선택
    for (int i = 0; i < cases.size(); i++)
    {
        // 감시 표시 후 새 배열 리턴
        vector<vector<int>> new_board = mark_monitored(r, c, cases[i], board);

        dfs(cnt + 1, new_board);
    }
}

/**
 * [ 감시 ]
 * CCTV의 방향을 적절히 정해서, 사각 지대의 최소 크기를 구하는 프로그램
 *
 * 방법 1.
 *
 * 왼쪽 위부터 CCTV를 하나씩 확인하면서 가장 많은 영역을 감시할 수 있는 방향을 고정
 * 어떤 방향을 감시해야 가장 많은 영역을 감시할 수 있을지 확인하기 위해서,
 * 일단 CCTV의 가능한 모든 경우의 수에 대해서 감시할 수 있는 영역을 구한 후
 * 그 중에서 가장 최댓값에 해당하는 방향으로 고정한다. (그리디식)
 *
 * ? CCTV를 확인하는 순서는 영향이 없을까?
 * 어떤 CCTV를 먼저 확인하는지가 분명 영향을 미친다.
 * 따라서 순서대로 최대로 감시하는 경우로 고정하는 방법 1은 사용할 수 없다.
 * => 전체 경우의 수를 고려하는 방법 2를 활용한다.
 *
 * 방법 2.
 * CCTV의 개수 x 각 CCTV가 감시할 수 있는 방향의 경우의 수 를 전부 고려해준다.
 *
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
            if (board[i][j] >= 1 && board[i][j] <= 5)
            {
                cctvs.push_back({i, j});
            }
        }
    }

    dfs(0, board);

    cout << ans;
}