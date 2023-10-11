#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/**
[다리를 지나는 트럭]
https://school.programmers.co.kr/learn/courses/30/lessons/42583

1. 먼저 들어온 트럭이 먼저 나가는 FIFO 구조이므로 대기 트럭 리스트를 queue에 저장해서 사용.
2. 현재 다리 위의 트럭들이 어느 위치까지 움직였는지 어떻게 저장하지?
=> 배열의 인덱스를 거리로하는 벡터를 만들어서 단위 시간초가 지날때마다 트럭을 직접 한칸씩 움직여주기.

*/
int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;

    queue<int> q;

    for (int i = 0; i < truck_weights.size(); i++)
    {
        q.push(truck_weights[i]);
    }

    int total_weight = 0;
    int t = 0;
    int completed = 0;

    vector<int> trucks_on_bridge(bridge_length, 0);
    // trucks_on_bridge[i]: 현재 다리의 시작지점으로부터 i거리에 있는 트럭의 무게

    do
    {

        int last = trucks_on_bridge.size() - 1;

        if (trucks_on_bridge[last])
        { // 마지막에 트럭이 있으면 내린다.

            total_weight -= trucks_on_bridge[last];
            trucks_on_bridge[last] = 0;
            completed += 1; // 다리를 건넌 차
        }

        // 트럭내 트럭들 한칸씩 이동 O(n)
        for (int i = last; i >= 1; i--)
        {
            trucks_on_bridge[i] = trucks_on_bridge[i - 1];
        }
        trucks_on_bridge[0] = 0;

        // 새로운 트럭 진입

        if (!q.empty())
        { // 대기중인 트럭이 있을 경우에먼
            int truck = q.front();
            if (total_weight + truck <= weight)
            {
                trucks_on_bridge[0] = truck;
                total_weight += truck;
                q.pop();
            }
        }

        t++;

    } while (completed < truck_weights.size());

    return t;
}