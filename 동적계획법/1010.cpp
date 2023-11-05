#include <iostream>

using namespace std;

const int SIZE = 31;
long long dp[SIZE][SIZE] = {
    0,
}; // dp[i][j] == iCj , i>=j

void getCombination()
{

    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 1; j <= i; j++)
        {

            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if (j == 1)
            {
                dp[i][j] = i;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
}

/**
 * 백준 1010번 [다리 놓기]
 * https://www.acmicpc.net/problem/1010
 *
 * m개의 선택지 중에서 n 개를 고르는 순열의 경우의 수를 구하면 되는 문제.
 * n<=m<30 이므로 재귀로 경우의 수를 카운팅하면 스택 오버플로우 발생.
 * 각각의 경우의 수를 출력할 필요가 없으므로 dp 알고리즘을 활용해서 계산
 *
 * <순열 공식>
 *
 * nCr = n-1Cr-1 + n-1Cr
 * */
int main()
{

    getCombination();

    int t;
    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;

        cout << dp[m][n] << "\n";
    }
}