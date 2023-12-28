#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <deque>

using namespace std;

// 북 동 남 서 북서 북동 남서 남동

int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

typedef pair<int, int> ci;

vector<vector<int>> board; // 땅

bool cmp(const int &age1, const int &age2)
{

    return age1 < age2; //  나이 기준 오름차순
}

void springAndSummer(int n, deque<int> (&trees)[11][11])
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            deque<int> &currentDeque = trees[i][j]; // [i][j] 칸에 존재하는 나무들 목록

            if (currentDeque.size() == 0)
            {
                continue;
            }

            int idx = -1; // 죽기 시작하는 기준점 인덱스

            // 나무가 없으면
            for (int t = 0; t < currentDeque.size(); t++)
            {

                int needed_nutrient = currentDeque[t];

                if (board[i][j] < needed_nutrient) // 양분이 충분하지 않으면
                {
                    idx = t;

                    break;
                }
                currentDeque[t] += 1;
                board[i][j] -= needed_nutrient;
            }

            if (idx != -1) // 모든 나무에 양분을 줄 수 없을 경우
            {
                // 죽은 나무 양분
                for (int k = idx; k < currentDeque.size(); k++)
                {
                    board[i][j] += (currentDeque[k] / 2);
                }

                currentDeque.erase(currentDeque.begin() + idx, currentDeque.end()); // 나무가 죽기 시작하면 뒤의 나무가 다 죽음
            }
        }
    }
}

void fall(int n, deque<int> (&trees)[11][11])
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            deque<int> &currentDeque = trees[i][j]; // [i][j] 칸에 존재하는 나무들 목록

            for (int &age : currentDeque)
            {
                if (age % 5 == 0)
                {
                    // 인접한 8개의 칸에 나이가 1인 나무가 생긴다.

                    for (int d = 0; d < 8; d++)
                    {

                        int nx = i + dx[d];
                        int ny = j + dy[d];

                        if (nx < 1 || nx > n || ny < 1 || ny > n)
                        {
                            continue;
                        }

                        trees[nx][ny].push_front(1);
                    }
                }
            }
        }
    }
}

void winter(int n, vector<vector<int>> nutrient)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            board[i][j] += nutrient[i][j];
        }
    }
}

int countTotalTree(int n, deque<int> (&trees)[11][11])
{

    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            deque<int> &currentDeque = trees[i][j]; // [i][j] 칸에 존재하는 나무들 목록

            total += currentDeque.size();
        }
    }

    return total;
}

/**
 * [나무 재테크]
 *
 * " 나무 목록을 어떻게 관리할 것인가? " 많은 고민이 들었던 문제.
 *
 * 1. tree[x][y] 에 age 목록 저장
 *      - (x,y) 에 존재하는 나무의 나이를 O(1)에 알 수 있다.
 *      - 그러나 존재하는 나무 리스트를 확인하기 위해서 항상 모든 맵을 뒤져야 한다. O(N^2)
 *         ! 본 문제는 N<=10 으로 굉장히 작으므로 N^2 이 부담가는 값이 아니긴 함!
 *      - 그러나 같은 좌표에 여러개의 나무가 존재할 수 있으므로 격자형 벡터로 구현  + 각 좌표에 대해 정렬을 수행해주어야함
 *
 *  => 시간 복잡도 : 나무 정렬 O(MlogM) + 나무 확인 O(N^2) * 나무 개수 * 나무 삭제 O(한 땅에 자라는 나무 개수)
 *
 *
 * 2. vector<tree> 에 {x,y,age} 저장
 *      - 불필요한 곳을 확인할 필요 없이 존재하는 나무 목록을 바로 확인할 수 있다. O(m) m : 나무의 개수
 *      - 나무를 수정하는데에는 O(1) 이면 되지만, 나무 하나를 삭제하는데에 O(m) 만큼의 시간이 소요.
 *      - 매번 정렬해주어야한다. O(MlogM)
 *
 * => 시간 복잡도 : 나무 정렬( MlogM ) + 나무 확인 O(M) * 나무 삭제 O(M)
 *
 * 초기 M의 최댓값이 100이고, K<=1000 이므로 최소 200번 나무가 증식할 수 있다.
 * 따라서 M이 충분히 큰 수 일거라고 예측할 수 있다.
 * 따라서 어린 나무 순으로 꺼내기 위해서 매번 O(MlogM) 의 정렬을 수행하면 시간초과가 발생할 수 있다.
 * => 매번 sort 를 수행하는 것을 피해야한다!
 * => 오름차순 정렬 된 상태에서 어린 나무는 항상 앞에 삽입된다는 점을 활용!
 * => deque 자료형을 활용해 어린 나무를 항상 맨 앞에 삽입해준다.
 *
 * 3. deque <tree> [n][n] 에 age 저장
 *    - 격자형 벡터의 장단점을 그대로 가져오면서 어린 나무를 맨 앞부분에 O(1) 만에 삽입할 수 있다는 장점
 *    - 오름차순 정렬되어 있으니 나무가 죽기 시작하면 뒤는 다 죽는다는 점을 활용해 한번의 erase 로 디큐를 새롭게 갱신
 *
 *
 */
int main()
{

    int n, m, k, x, y, z;

    cin >> n >> m >> k;

    vector<vector<int>> nutrient(n + 1, vector<int>(n + 1, 0)); // 양분의 양
    deque<int> trees[11][11];                                   // 각 좌표 당 나무들
    board.assign(n + 1, vector<int>(n + 1, 5));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> nutrient[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;

        trees[x][y].push_back(z);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            deque<int> &currentDeque = trees[i][j]; // [i][j] 칸에 존재하는 나무들 목록

            sort(currentDeque.begin(), currentDeque.end(), cmp); // 나이 기준 오름차순 정렬
        }
    }

    while (k--)
    {

        springAndSummer(n, trees);
        fall(n, trees);
        winter(n, nutrient);
    }

    cout << countTotalTree(n, trees);
}