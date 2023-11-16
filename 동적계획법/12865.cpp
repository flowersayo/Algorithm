#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

/**
 * [평범한 배낭]
 *
 * 최대 무게 K 일 때의 최대 가치합을 구하는 dp (Knapsack Problem) 유형의 문제!
 *
 * k이전의 무게들에 대한 정답(가치 합의 최댓값)을 통해
 * 즉, 작은 부분 문제의 해답을 통해 더 큰 문제의 해답을 알 수 있다.
 *
 *
 * 따라서 다음과 같은 점화식을 도출할 수 있다.
 * dp[i][j] : i번째 물건까지 고려했을 때, 최대 무게가 j인 가방의 가치합의 최댓값
 * => 현재 물품인 i를 가방에 넣는 경우 or 넣지 않는 경우 중 최댓값을 저장하자!
 *
 *
 * dp[i][j] = max(dp[i-1][j - i번째 물품의 무게] + i번째 물품의 가치 , dp[i-1][j])
 * 이때, i번째 물품의 무게 <= j
 *
 * Q. dp[i][k] 에서 최대 무게가 k 이지만, 여유 공간이 있을 수도 있는데 그러면
 * 이전에 넣었던 물품을 빼지 않고 가치만 더할 수 있는 경우  ( dp[i-1][j] + i번째 물품의 가치 ) 는
 * 고려하지 않아도 괜찮은가?
 *
 * A. 만약 dp[i][k] 의 공간에 여유가 있다면, dp[i][k-여유공간] 에도 dp[i][k] 의 값이 저장되어 있을 것.
 * 따라서 항상 현재 물건을 넣을 만큼의 여유공간이 있는 경우는 dp[i-1][j - i번째 물품의 무게] + i번째 물품의 가치 를 계산하는 것에서 같이 고려된다.
 * ( dp[i-1][j - i번째 물품의 무게] + i번째 물품의 가치 = dp[i-1][j] + i번째 물품의 가치 가 성립하기 때문 )
 *
 *
 */
int dp[101][100001] = {
    0,
};

int main()
{

    int n, k;

    cin >> n >> k;

    vector<ci> products;

    int w, v;

    for (int i = 0; i < n; i++)
    {
        cin >> w >> v;

        products.push_back({w, v});
    }

    // 첫번째 물건 초기화

    for (int j = 1; j <= k; j++)
    {
        if (j >= products[0].first)
        {
            dp[0][j] = products[0].second;
        }
    }

    for (int i = 1; i < n; i++) // 물건 인덱스
    {
        for (int j = 1; j <= k; j++)
        {

            if (j >= products[i].first)
            {
                dp[i][j] = max(dp[i - 1][j - products[i].first] + products[i].second,
                               dp[i - 1][j]);
            }
            else
            {                            // 현재 최대 가방의 무게 j 보다 물품의 무게가 더 무거워서 담을 수 없는 경우
                dp[i][j] = dp[i - 1][j]; // 이전 값을 그대로 가져온다
            }
            //  cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }

    cout << dp[n - 1][k];
}