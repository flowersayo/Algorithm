#include <iostream>
#include <algorithm>

using namespace std;

vector<int> snacks;

// 길이가 최소 k 이상인 과자의 개수 리턴
int calc(int k)
{

    int cnt = 0;
    for (int i = snacks.size() - 1; i >= 0; i--)
    {

        if (snacks[i] < k)
        {
            break;
        }

        cnt += (snacks[i] / k);
    }

    return cnt;
}

int upperSearch(int left, int right, int target)
{

    int ans = 0;

    while (left <= right)
    {

        int mid = (left + right) / 2; // 막대과자의 길이

        int cnt = calc(mid); // 만족하는 조카의 수

        // cout<<"mid:"<<mid<<"cnt:"<<cnt<<"\n";
        if (cnt < target)
        { // 모자라면

            right = mid - 1; // 과자의 길이를 더 짧게
        }
        else
        { // 만족하면

            ans = mid;
            left = mid + 1; // 과자의 길이를 더 길게
        }
    }

    return ans;
}
/**
 * [과자 나눠주기]
 * https://www.acmicpc.net/problem/16401
 *
 * 최적화 문제를 결정 문제로 바꾸는 parametricSearch
 *
 * "M명의 조카가 있고 N개의 과자가 있을 때, 조카 1명에게 줄 수 있는 막대 과자의 최대 길이는?"
 * => "막대 과자의 길이가 i 일때, M명의 조카에게 과자를 나누어줄 수 있는가?"
 *
 * arr[i] = k (막대과자의 길이가 i 일때, 최대 k 명의 조카에게 과자를 나누어 줄 수 있음) 일때,
 * arr[i] = m 을 만족하는 i 값 중 최댓값 => upperSearch!
 *
 */

int main()
{
    int m, n; // 조카 수, 과자 수

    cin >> m >> n;

    snacks.assign(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> snacks[i];
    }

    sort(snacks.begin(), snacks.end());

    cout << upperSearch(1, snacks[n - 1], m);

    return 0;
}