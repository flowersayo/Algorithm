#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

const int SIZE = 8;

const int RIGHT = 2;
const int LEFT = 6;

int top[5] = {
    0,
}; // top[i] : i 번 톱니 바퀴의 12시 방향의 인덱스

vector<int> canRotate(int n, int d, vector<vector<int>> &gears)
{

    vector<int> rotate(5, 0); // rotate[i] : i 번째 톱니바퀴가 어떤 방향으로 돌아가야하는지 나타냄.
    // 1: 시계, -1: 반시계, 0: 돌아가지 않음.

    rotate[n] = d;
    int current = n, direction = d;

    int left;

    // 왼쪽 연계 확인
    while ((current - 1) >= 1)
    {

        left = current - 1;
        direction = direction == 1 ? -1 : 1; // 방향 전환
        if (gears[current][(top[current] + LEFT) % SIZE] == gears[left][(top[left] + RIGHT) % SIZE])
        {

            break;
        }

        rotate[left] = direction;

        current--;
    }

    // 기준점 초기화
    current = n;
    direction = d;

    // 오른쪽 연계 확인
    int right;
    while ((current + 1) <= 4)
    {

        right = current + 1;
        direction = direction == 1 ? -1 : 1;

        if (gears[current][(top[current] + RIGHT) % SIZE] == gears[right][(top[right] + LEFT) % SIZE])
        {

            break;
        }
        rotate[right] = direction;

        current++;
    }

    return rotate;
}

void engage(vector<int> rotate)
{

    for (int i = 1; i <= 4; i++)
    {

        top[i] = (top[i] - rotate[i] + SIZE) % SIZE;
    }

    // rotate[i] 가 0 이면 그대로 유지된다.
}

int calcScore(vector<vector<int>> &gears)
{
    int sum = 0;
    for (int i = 1; i <= 4; i++)
    {

        if (gears[i][top[i]] != 0)
        {
            sum += pow(2, i - 1);
        }
    }

    return sum;
}
/**
 * [ 톱니 바퀴 ]
 * https://www.acmicpc.net/problem/14891
 *
 * 벡터에서 톱니 바퀴를 직접 이동 시키는 것은 너무 시간이 오래걸리는 일
 * 톱니 바퀴의 방향을 바꿀 때 마다, 3시 방향의 기준점을 변화시키자!
 *
 * n번 톱니바퀴를 회전시키면 인접해있는 n-1, n+1 톱니바퀴가 영향을 받는다.
 *
 * 시계 방향으로 돌리면 기준점이 -1 씩 작아지고 반시계 방향으로 돌리면 기준점이 1 씩 커진다.
 *
 * 톱니 바퀴를 직접 돌리면서 구현하려고 하면 톱니 바퀴를 돌리기 이전의 상태가 필요하므로 구현이 복잡하다.
 * => 톱니 바퀴를 돌리기 전에 특정 톱니 바퀴가 돌아갈지 여부를 저장하고, 그 결과에 따라 한번에 톱니바퀴를 돌린다.
 *
 * N극 : 0 , S극 : 1
 * 방향 : 1 -> 시계 방향, 2 -> 반시계 방향
 *
 */

int main()
{
    int k, n, d;
    vector<vector<int>> gears(4 + 1, vector<int>(SIZE, 0));

    string str;
    for (int i = 1; i <= 4; i++)
    {

        cin >> str;
        for (int j = 0; j < SIZE; j++)
        {
            gears[i][j] = str[j] - '0';
        }
    }

    cin >> k;

    while (k--)
    {

        cin >> n >> d;

        vector<int> rotate = canRotate(n, d, gears);
        engage(rotate);
    }

    cout << calcScore(gears);
}