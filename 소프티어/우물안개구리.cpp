#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n, m;

    cin >> n >> m;

    vector<vector<int>> relations(n + 1, vector<int>(0));

    vector<int> weight(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];
    }

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        relations[a].push_back(b);
        relations[b].push_back(a);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {

        bool amIbest = true;

        for (int j = 0; j < relations[i].size(); j++)
        { // 본인과 연관된 관계 확인

            if (weight[i] <= weight[relations[i][j]])
            {
                amIbest = false;
            }
        }

        if (amIbest)
        {
            ans++;
        }
    }

    cout << ans;

    return 0;
}