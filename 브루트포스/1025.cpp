#include <iostream>
#include <math.h>

using namespace std;

int n, m, ans = -1, chart[10][10];

bool isSquare(int num)
{
    int root = (int)sqrt(num);
    return root * root == num;
}

int main()
{
    cin >> n >> m;

    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;

        for (int j = 0; j < m; j++)
        {
            chart[i][j] = str[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) // 행
    {
        for (int j = 0; j < m; j++) // 열
        {
            for (int r_d = -n; r_d < n; r_d++) // 행 등차
            {
                for (int c_d = -m; c_d < m; c_d++) // 열 등차
                {

                    if (!r_d && !c_d) // 행, 열 등차가 모두 0인 경우 제자리 걸음 무한루프 방지
                    {
                        continue;
                    }

                    int r = i, c = j, num = 0;
                    while (0 <= r && r < n && 0 <= c && c < m)
                    {
                        num *= 10;
                        num += chart[r][c];
                        r += r_d, c += c_d;
                        if (isSquare(num))
                        {
                            ans = max(ans, num);
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}