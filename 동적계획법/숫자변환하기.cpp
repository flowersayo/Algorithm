#include <string>
#include <vector>

using namespace std;

const int INF = 1000001;
int solution(int x, int y, int n)
{

    // dp[i] : i 를 만들기 위한 최소 횟수 ( x->y )
    // dp[i] = min(dp[i-n],dp[i/2],dp[i/3]) +1
    int answer = 0;

    int dp[1000001];

    fill_n(dp, 1000001, INF);

    // bottom up
    dp[x] = 0;
    for (int i = x + 1; i <= y; i++)
    {

        if ((i - n) >= x)
        {
            dp[i] = min(dp[i], dp[i - n] + 1);
        }

        if (i % 2 == 0 && (i / 2) >= x)
        {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }

        if (i % 3 == 0 && (i / 3) >= x)
        {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    if (dp[y] == INF)
    {
        return -1;
    }

    return dp[y];
}