#include <iostream>
#include <vector>

using namespace std;

/**
 * 최장 부분 수열의 길이 (LCS)
 * https://www.acmicpc.net/problem/11053
 *
 * 어떠한 수열에서 오름차순으로 증가하는 가장 긴 부분수열을 구한다. ( 부분 수열의 각 수는 연속할 필요는 없다. )
 *
 *
 * 1. 완전 탐색?
 * 수열의 개수를 n이라고 하면, 모든 부분 수열의 가짓 수는 2^n가지 이므로
 * 모든 부분 수열을 확인해 오름차순 정렬을 확인하는 것은 비효율적이다.
 *
 * 2. DP (동적 계획법)
 * dp[i] : i 번째 원소로 끝나는 최장 부분 수열의 길이 를 생각해보자.
 * 따라서 i의 앞 순서에 있는 모든 원소들 중 값이 arr[i] 보다 작은 원소에 대해,
 * 그 각각의 원소에서 끝나는 최장 증가 수열의 길이를 알고 있다면, i에서 끝나는 최장 증가 수열의 길이도 알 수 있다.
 *
 * 즉, dp[i] = max(dp[i],dp[j]+1) 단, arr[i] > arr [j]
 * 시간 복잡도 : O(N^2)
 *
 * 3. 이분 탐색 활용
 *
 * 같은 크기의 증가수열에서 마지막 값 중 최솟값만 기억하면 문제를 풀어낼 최적화된 단서를 찾을 수 있다!
 *  lis[len] = 0~i의 arr의 원소배열 중 LIS의 길이가 len인 부분수열들의 마지막 값 중 최솟값
 * 현재 원소를 하나씩 배열에 넣어 LIS를 유지하려고 할 때, 그 최적의 위치를 찾는 것
 *
 * 시간 복잡도 : O(NlogN)
 *
 *
 */

int sol_dp(int n, vector<int> arr)
{

    vector<int> dp(n, 1);
    dp[0] = 1;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        // i 이전까지의 수열들 중
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(dp[i], ans); // 최장 수열 길이 갱신
    }
}

// target 이상의 숫자가 처음으로 등장하는 지점
int lower_bound(int left, int right, int target, vector<int> &lis)
{

    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (lis[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return right + 1;
}

int sol_binary_search(int n, vector<int> arr)
{
    vector<int> lis;
    lis.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {

        if (arr[i] > lis.back())
        {
            lis.push_back(arr[i]);
        }
        else
        {
            int pos = lower_bound(0, lis.size() - 1, arr[i], lis);
            lis[pos] = arr[i]; // 더 작은 값으로 갱신
        }
    }

    return lis.size();
}
int main()
{

    int n;

    cin >> n;

    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // cout << sol_dp(n,arr);

    cout << sol_binary_search(n, arr);
}