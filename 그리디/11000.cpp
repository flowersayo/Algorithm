#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

// 끝나는게 이른 순으로 정렬

/**
 * 강의실 배정
 * https://www.acmicpc.net/problem/11000
 *
 * 끝나는 시간이 빠른 강의부터 차곡차곡 쌓아나간다.
 * 각각의 강의실의 끝나는 시간을 저장해두고, 현재 강의의 시작시간과 비교한다.
 * 현재 강의를 이미 존재하는 강의실에 넣을 수 없다면 새로운 강의실을 추가한다.
 *
 * 이 때, 이미 존재하는 모든 강의실을 뒤지면서 들어갈 수 있는지 확인하면 시간초과가 발생한다.
 * => 우선 순위 큐 최소 힙을 활용하여 O(logN) 가장 수업이 일찍 끝나는 시간을 top 에 유지할 수 있도록 한다.
 * 이렇게 함으로서 O(1)만에 해당 강의가 들어갈 자리가 있는지 판단할 수 있다.
 * 가장 일찍 수업이 끝나는 강의실에도 못들어갔으면 그것 보다 수업이 늦게끝나는 강의실에는 당연히 못들어가기 때문이다.
 *
 * Q. 강의실의 정렬기준? 
 * A. 시작 시간을 기준으로 오름차순 정렬을 수행해준다. 
 *
 */
int main()
{

    int n;

    cin >> n;

    vector<ci> lectures(n);

    for (int i = 0; i < n; i++)
    {
        cin >> lectures[i].first >> lectures[i].second;
    }

    // 시작 시간을 기준으로 오름차순 정렬
    sort(lectures.begin(), lectures.end());

    priority_queue<int, vector<int>, greater<int>> minHeap; // 최소 힙
    minHeap.push(lectures[0].second);

    for (int i = 1; i < lectures.size(); i++)
    {

        if (minHeap.top() <= lectures[i].first)
        {
            minHeap.pop();
            minHeap.push(lectures[i].second);
        }
        else
        {
            minHeap.push(lectures[i].second); // 강의실 추가
        }
    }

    cout << minHeap.size();
    return 0;
}