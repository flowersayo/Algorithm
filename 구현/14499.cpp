#include <iostream>
#include <vector>

using namespace std;

int dice[6] = {
    0,
}; // 뒤, 위(윗면) , 앞 , 아래(바닥면) , 왼쪽 , 오른쪽

// X 동 서 북 남
int dx[5] = {0, 0, 0, -1, 1}; // 행
int dy[5] = {0, 1, -1, 0, 0}; // 열

void move(int direction)
{

    if (direction == 1)
    { // 동

        int temp = dice[3];

        dice[3] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = temp;
    }
    else if (direction == 2)
    { // 서

        int temp = dice[3];

        dice[3] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = temp;
    }
    else if (direction == 3)
    { // 북
      // 0 ~ 3 을 왼쪽으로 shift

        int temp = dice[0];
        for (int i = 0; i <= 2; i++)
        {
            dice[i] = dice[i + 1];
        }

        dice[3] = temp;
    }
    else if (direction == 4)
    { // 남
        // 0 ~ 3 을 오른쪽으로 shift

        int temp = dice[3];
        for (int i = 2; i >= 0; i--)
        {
            dice[i + 1] = dice[i];
        }

        dice[0] = temp;
    }
}
/**
 * 백준 14499번 주사위 굴리기
 * https://www.acmicpc.net/problem/14499
 * 주사위가 이동할 때마다, 전개도에 표기된 값을 업데이트 해준다.
 * 이 때, 주사위 정보는 다음과 같은 형태로 1차원 배열에 저장한다.
 *
 *     0
 *   4 1 5
 *     2
 *     3
 *
 * 각 면에 표기된 숫자는 dice배열의 몇번 째 인덱스에 값이 저장될 것인지를 의미한다.
 * 주사위가 특정 방향으로 이동할 때마다, 다음 규칙을 따라서 전개도에 적힌 수가 옮겨진다.
 * - 동 :
 * - 서 :
 * - 남 : 0
 * - 북 :
 *
 * */
int main()
{

    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;

    vector<vector<int>> board(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int direction;
    while (k--)
    {

        cin >> direction;

        int nx = x + dx[direction];
        int ny = y + dy[direction];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        {

            continue;
        }

        x = nx;
        y = ny;

        move(direction); // 주사위 움직이기

        if (board[x][y] == 0)
        {
            board[x][y] = dice[3]; // 주사위 -> 바닥면 복사
        }
        else
        {

            dice[3] = board[x][y]; // 바닥면 -> 주사위 복사
            board[x][y] = 0;
        }

        cout << dice[1] << "\n";
    }
}