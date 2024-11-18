#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    ios::sync_with_stdio(false); // C와 C++의 입출력 버퍼를 분리
    cin.tie(NULL);               // cin과 cout의 묶음을 풀어서 속도 향상

    int n, m, target;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end()); // 이분탐색은 정렬 필수!

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> target;

        int num = upper_bound(arr.begin(), arr.end(), target) - lower_bound(arr.begin(), arr.end(), target);
        cout << num << " ";
    }
}
