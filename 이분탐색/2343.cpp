#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> lectures;

const int INF = 10000 * 100000;

int calc(long long size)
{ // 블루레이 크기가 size 일때, 필요한 최소 블루레이 개수

    int cnt = 1;
    long long sum = 0; // 현재 채워진 양

    for (int i = 0; i < lectures.size(); i++)
    {

        if (sum + lectures[i] <= size)
        { // 기존 블루레이에 강의 추가
            sum += lectures[i];
        }
        else
        { // 초과하면 새로운 블루레이 도입
            sum = lectures[i];
            cnt++;
        }
    }

    return cnt;
}

int lowerSearch(long long left, long long right, int target)
{

    long long ans = right; // 블루레이의 최대 크기

    while (left <= right)
    {

        long long mid = (left + right) / 2; // 블루레이 길이
        int needed = calc(mid);             // 필요한 블루레이 개수

        if (needed <= target)
        { // 목표치보다 더 적은 개수가 필요하다면

            /*
            현재 사이즈에서 needed <= target 라면(=실제 필요한 개수보다 주어진 개수가 더 많다면)
            블루레이 여분이 생겨서 충분히 널널하게 담을 수 있다는 뜻이므로 ans = mid; 업데이트를 여기서 해준다.
            */
            right = mid - 1; // 블루레이 길이 줄여서 개수를 늘림
            ans = mid;
        }
        else if (needed > target)
        {                   // 더 많이 필요하면
            left = mid + 1; // 블루레이 길이를 늘려서 개수를 줄임
        }
    }

    return ans;
}

/**
 * [기타 레슨]
 * https://www.acmicpc.net/problem/2343
 *
 * 최적화 문제를 결정 문제로 바꾸는 parametric search
 *
 * "블루레이 개수가 n개 일때, 가능한 최소 블루레이 크기는?"
 * => "블루레이 크기가 i일때, 필요한 블루레이 개수는?"
 * arr[i] = k (블루레이 크기가 i일때, 최적의 블루레이 개수)
 *
 * arr[i] = n 을 만족하는 i 값 중 최솟값 => lower bound!
 *
 *
 * ! 블루레이의 최대 크기는 100,000 * 10,000 (최대 강의 개수 * 최대 강의 크기 ) 라서 int 범위를 초과함에 유의 !
 */

int main()
{

    int n, m; // 강의 수, 블루레이 개수
    cin >> n >> m;

    lectures.assign(n, 0);

    long long sum = 0;
    int max_size = -1;
    for (int i = 0; i < n; i++)
    {

        cin >> lectures[i];
        sum += lectures[i];
        max_size = max(max_size, lectures[i]);
    }

    // 블루레이의 크기는 적어도 가장 긴 강의 크기 보다는 커야함.
    // 블루레이의 최대 크기 = 모든 강의들을 합한 양
    cout << lowerSearch(max_size, sum, m);
}