#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**
[징검다리]
https://school.programmers.co.kr/learn/courses/30/lessons/43236

원하는 조건을 만족하는 가장 알맞은 값을 찾는 문제
=> 최적화 문제를 결정문제로 바꾸어 해결하는 파라메트릭 서치 활용

바위 사이의 간격의 최솟값이 최대화되고자 하므로, '바위사이의간격'을 기준으로 두고 문제를 풀어야한다.
즉, 이분탐색으로 설정하는 하는 것은, 바위를 제거할 간격을 기준으로 잡아주는 것이다.

"몇 개의 바위를 제거해야 최솟값을 만들 수 있을까?"
=> "거리사이 최솟값 = k 라고 가정하고, n개의 바위를 제거해서 이를 만족시킬 수 있는가?"

만일 n개 이하로 바위가 제거된다면, 거리의 최솟값을 더 늘려보고
n개 초과해서 바위가 제거된다면, 거리의 최솟값을 좁혀본다.
=> 이런식으로 가장 최댓값을 찾을 때까지 바위 사이의 거리 distance를 반복해서 조정한다.
=> 만족하는 k 값 중 최댓값을 찾기 위해 탐색을 지속한다. (upper bound)

! 아무리 제거해도 더 작은 최솟값이 더 이상 발생하지 않아 n개의 바위가 제거되전에
바위사이의 최소 간격이 최대구간이 되는 부분이 발생한다.
=> numOfRemovedRocks == n 일때가 아니라, numOfRemovedRocks <= n 일때 정답을 갱신해준다!
*/

int countNumOfRemovedRocks(int n, int min_dist, int distance, vector<int> rocks)
{ // 최소 거리 min_dist를 만족하기 위해 지워야하는 바위 개수

    int remove_cnt = 0; // 최소거리 k를 만들기 위해서 제거해야하는 바위 수

    // 최소거리 k를 만들기 위해서 필요한 바위개수 카운트
    // 배열의 처음부터 확인하면서 최소거리가 k 미만이면 바위를 지운다.

    int before = 0; // 이전 바위의 위치
    rocks.push_back(distance);

    // 적어도 모든 바위가 제거되고 나면 btnDist >= min_dist 가 될테니까
    // remove_cnt > 바위개수 인 상황은 발생하지 않는다.
    for (int i = 0; i < rocks.size(); i++)
    {

        int btnDist = rocks[i] - before;
        if (btnDist < min_dist)
        {
            remove_cnt++; // 제거해야하는 바위 개수 추가
        }
        else
        {
            before = rocks[i]; // 이전 바위 위치 업데이트
        }
    }

    return remove_cnt;
}

int parametricSearch(int start, int end, int n, int distance, vector<int> rocks)
{

    // 이진 탐색 수행 (반복적)
    int result = 1;

    while (start <= end)
    {

        int mid = (start + end) / 2; // 가정한 거리값

        int numOfRemovedRocks = countNumOfRemovedRocks(n, mid, distance, rocks);
        if (numOfRemovedRocks > n)
        { // 제거해야하는 수가 n개보다 많다면

            end = mid - 1; // 최소거리를 더 좁혀서 덜 제거해도 되게끔
        }
        else if (numOfRemovedRocks <= n)
        { // 제거해야하는 수가 n개 미만이라면

            start = mid + 1;           // 최소거리를 더 늘려봐도 됨 (최댓값을 구하기 위해서)
            result = max(mid, result); // 정답 갱신
        }
    }
    return result;
}

int solution(int distance, vector<int> rocks, int n)
{

    sort(rocks.begin(), rocks.end()); // 오름차순

    int answer = parametricSearch(1, distance, n, distance, rocks);
    return answer;
}