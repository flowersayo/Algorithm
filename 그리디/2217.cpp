#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, ans = 0; // 초기화 꼭 해줄 것!
    cin >> n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int k = 1; k <= n; k++) // 선택하는 로프 개수
    {
        ans = max(ans, arr[n - k] * k); // 가장 최소 중량 기준으로 k개만큼 커버 가능
    }

    cout << ans;
}