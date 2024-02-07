#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int t;
    long long n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        cout << (n % 10 == 0) << "\n";

        // 10의 배수이면 후공인 상윤이가 항상 10의 배수를 유지할 수 있으므로 0 출력
        // 10의 배수가 아니면 선공인 승우가 항상 10의 배수를 유지할 수 있으므로 1 출력
    }
}