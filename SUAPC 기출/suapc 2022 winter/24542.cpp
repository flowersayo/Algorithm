#include <iostream>
#include <vector>

using namespace std;
/**
 * 튜터-튜티 관계의 수
 *
 * https://www.acmicpc.net/problem/24542
 *
 * 자료를 전달받는 인원이 최소로 되길 원하므로 하나의 트리에 단 한 명의 인원만 자료를 전달받아야 한다.
 * (각 트리에서 한명만 전달받으면 어떤식으로든 모두에게 전달할 수 있다.)
 *
 * 트리 내의 모든 인원이 각각 처음으로 자료를 전달받는 사람이 될 수 있다고 가정한다면
 * 한 명이 특정 튜터로 확정되면, 그 시작점으로부터 모든 인원에게 자료를 나누어줄 수 있도록 단 하나의 흐름(튜터-튜티 관계)이 형성된다.
 * 따라서 주어지는 친분 관계로 만들어지는 그래프들에서 각 그래프 당 인원수를 곱하면 그것이 정답이 된다.
 *
 */

vector<bool> visited;
vector<vector<int>> adj_list;

const int MOD = 1000000007;
int dfs(int n) // n과 연결된 관계의 수
{

    visited[n] = true;
    int total = 1;
    for (auto neighbor : adj_list[n])

    { // 인접한 사람들 방문하기

        if (!visited[neighbor])
        {
            total += dfs(neighbor);
        }
    }

    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m; // 교육생 수, 친분 관계 수
    cin >> n >> m;

    adj_list.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);

    int u, v;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<int> team_size;

    for (int i = 1; i <= n; i++)
    {

        if (visited[i])
        {
            continue;
        }

        int size = dfs(i);

        team_size.push_back(size);
    }

    int answer = 1;

    for (auto size : team_size)
    {
        answer *= size;
        answer %= MOD;
    }
    cout << answer;
}