#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> ci;
vector<vector<int>> board;

// 북 동 남 서
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

const int INF = 987654321;

/**
 * 치킨 배달
 * https://www.acmicpc.net/problem/15686
 *
 * 1. next_permutation 으로 m 개의 치킨집을 선택하는 모든 조합 구하기
 * 2. 각각의 경우의 수에 대해 각 집에서 치킨집까지 최소 거리를 구한다.
 * 3. 모든 치킨 거리 합을 구하고 최솟값 갱신
 *
 * ! 치킨집과 집 사이에 아무런 장애물이 없으므로 굳이 bfs 를 이용할 필요 없이 점과 점 사이 공식 이용해주면 된다.
 */

int getChickenDistance(int n, vector<ci> homes, vector<ci> &selected)
{

    int sum = 0;
    for (int i = 0; i < homes.size(); i++)
    {

        int home_x = homes[i].first;
        int home_y = homes[i].second;

        int nearest_dist = INF;

        // 3곳의 치킨집 중 가장 가까운 곳 찾기
        for (int j = 0; j < selected.size(); j++)
        {

            int chicken_x = selected[j].first;
            int chicken_y = selected[j].second;

            int dist = abs(home_x - chicken_x) + abs(home_y - chicken_y);

            nearest_dist = min(dist, nearest_dist); // 최솟값 갱신
        }

        sum += nearest_dist;
    }

    return sum; // 모든 집의 치킨 거리의 합
}

int main()
{

    vector<ci> chickens;
    vector<ci> homes;

    int n, m;

    cin >> n >> m;

    board.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 2)
            {
                chickens.push_back({i, j});
            }
            if (board[i][j] == 1)
            {
                homes.push_back({i, j});
            }
        }
    }

    vector<int> combination;

    vector<ci> selected(n); // 치킨집이 선택되었는지

    for (int i = 0; i < chickens.size() - m; i++)
    {
        combination.push_back(0);
    }

    for (int i = 0; i < m; i++)
    {
        combination.push_back(1);
    }

    int ans = INF;
    do
    {
        selected.clear();

        // 선택된 치킨 집 마크
        for (int i = 0; i < combination.size(); i++)
        {

            if (combination[i])
            {
                int r = chickens[i].first;
                int c = chickens[i].second;

                selected.push_back({r, c});
            }
        }

        ans = min(ans, getChickenDistance(n, homes, selected));
    } while (next_permutation(combination.begin(), combination.end()));

    cout << ans;
}