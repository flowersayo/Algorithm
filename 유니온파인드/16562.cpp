#include <iostream>
#include <vector>

using namespace std;

vector<int> parent; // 부모 정점 저장
vector<int> cost;   // cost[i] : 루트 정점 i를 포함하는 그래프에서 가장 최소비용

int findParent(int x)
{
    if (parent[x] < 0)
    {
        return x;
    }

    return parent[x] = findParent(parent[x]); // 그래프 압축하며 루트 정점 찾기
}

void unionInput(int x, int y)
{

    int xp = findParent(x); // x의 루트 정점
    int yp = findParent(y); // y의 루트 정점

    if (xp == yp) // 이미 같은 집합에 속한 경우
    {
        return;
    }

    // 그룹 합치기

    if (parent[xp] < parent[yp]) // x 를 포함하는 집합의 크기가 더 크면 y가 포함된 그룹을 x 그룹으로 조인
    {
        parent[xp] += parent[yp];
        parent[yp] = xp;

        cost[xp] = min(cost[yp], cost[xp]); // 더 친구비용이 싼 값
    }
    else
    { // y 를 포함하는 집합의 크기가 더 크면 x가 포함된 그룹을 y 그룹으로 조인
        parent[yp] += parent[xp];
        parent[xp] = yp;

        cost[yp] = min(cost[yp], cost[xp]); // 더 친구비용이 싼 값
    }
}

/**
 * [16562] 친구비
 *
 * 유니온 파인드로 같은 집합끼리 묶고, 본인과 다른 집합에 속해있는 친구들 중 가장 친구 비용이 적은 친구를 선택해서 친구를 맺는다.
 *
 */

int calcCost(int n, int k)
{
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        if (parent[i] < 0)
        {                   // 루트 정점이면
            sum += cost[i]; // 최소비용 더하기
        }
    }

    if (k >= sum) // 비용을 감당할 수 있으면
    {
        return sum;
    }
    return -1;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, v, w;

    // 입력
    cin >> n >> m >> k;
    parent.assign(n + 1, -1);
    cost.assign(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {

        cin >> cost[i];
    }

    for (int i = 0; i < m; i++)
    {

        cin >> v >> w;
        unionInput(v, w); // v와 w 를 결합
    }

      int answer = calcCost(n, k);
    if (answer == -1)
    {
        cout << "Oh no";
    }
    else
    {
        cout << answer;
    };
}