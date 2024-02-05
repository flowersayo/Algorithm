class Solution
{
public:
    // 동전들 사이의 관계가 배수관계가 아니므로, 항상 큰 동전을 먼저 사용하는 것이 최소 동전 수를 보장한다고 볼 수 없다.
    // 그리디 방식의 풀이 대신 dp 활용!
    // dp[i] : i원을 만들기 위해 필요한 최소 동전 수

    const int SIZE = 10000;

    int coinChange(vector<int> &coins, int amount)
    {

        int dp[SIZE + 1];

        dp[0] = 0;

        for (int i = 1; i <= SIZE; i++)
        {
            dp[i] = -1; // 동전 만들 수 없는 경우 -1
        }

        for (int i = 1; i <= amount; i++)
        {

            int min_coin = SIZE; // 동전 조합 최댓값

            for (int j = 0; j < coins.size(); j++)
            {

                if (i - coins[j] < 0 || dp[i - coins[j]] == -1)
                { // 범위를 벗어나거나 동전을 만들 수 없는 경우
                    continue;
                }

                // 최적화 -> i-coins[j] == 0 이라는 것은 i = coins[j] 라는 것 따라서 코인 하나로 i원을 만들 수 있음.
                // 그러면 초기화하는 구문도 여기서 동시에 작성 가능
                // dp[0] = 0 이므로 min_coin 은 특정 동전의 경우는 항상 0 을 가리키게 됨.

                min_coin = min(min_coin, dp[i - coins[j]]);
                dp[i] = min_coin + 1;
            }
        }

        return dp[amount];
    }
};
