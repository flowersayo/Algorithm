#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> house;

// 모든 공유기 사이 거리가 최소 dist이상이도록 공유기를 설치했을 때, 설치된 공유기 숫자
int router(int dist)
{

    int cnt = 1;         // 첫번째 집에 무조건 공유기 설치
    int last = house[0]; // 마지막 공유기 위치
    for (int i = 1; i < house.size(); i++)
    {

        if (house[i] - last >= dist)
        { // 간격이 dist 이상이면
            cnt++;
            last = house[i];
        }
    }

    return cnt; // 설치될 공유기 수
}

// 가능한 최대 거리 중 가장 큰 값 (=upper bound)
int upperSearch(int left, int right, int target)
{
    int ans = 0;

    while (left <= right)
    {

        int mid = (left + right) / 2;
        int installed = router(mid);

        if (installed >= target)
        { // 공유기 target 개를 설치할 수 있으면
            // break 하지 않고 계속 탐색함으로써 upperSearch 가능!
            left = mid + 1; // 거리를 더 늘려봄
            ans = mid;      // 최댓값 갱신
        }
        else
        {
            right = mid - 1; // 거리를 더 좁혀봄
        }
    }
    return ans;
}
/**
 * [공유기 설치]
 * https://www.acmicpc.net/problem/2110
 * 최적화 문제를 결정문제로 바꾸는 parametric search
 *
 * "공유기 c 개를 설치할 때, 가장 인접한 두 공유기 사이의 최대거리는?"
 * => "가장 인접한 두 공유기 사이 거리가 k일때, 공유기 c개를 설치할 수 있는가?"
 * arr[i] = k (가장 인접한 공유기 사이 거리가 i 일때, 설치할 수 있는 최대 공유기 개수)
 * arr[i] = c 를 만족하는 i 값 중 최댓값이 정답 => upperSearch!
 *
 */

int main()
{

    int n, c;

    // 입력
    cin >> n >> c;
    house.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> house[i];

    // 연산
    sort(house.begin(), house.end());

    // 연산 & 출력
    // 공유기 사이의 최단 거리 (left) : 1
    // 공유기 사이의 최장 거리 (right) : 가장 멀리 있는 두 집 사이의 거리
    cout << upperSearch(1, house[n - 1] - house[0], c);
}