#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef pair<int, int> ci;

/**
[다리를 지나는 트럭] ver_2
https://school.programmers.co.kr/learn/courses/30/lessons/42583



사실 이 문제에서 큐를 어디에 활용해야하는지 고민이 들었었다.
다리 위에 있는 트럭 리스트를 담으려고 queue를 쓰기에는
queue는 배열처럼 모든 원소에 바로 접근하기에 편리한 원소가 아니므로
차 하나하나들을 꺼내서 특정 처리(ex. 거리를 늘려줌) 를 해주기 어려울 것이라고 생각했다.

그러나 애초에 트럭을 다리에 올릴 때, "해당 트럭이 다리를 건너는 시간" 을 큐에 같이 저장하면,
이전 풀이처럼 매 단위시간(t)마다 모든 차들의 경과시간(=이동거리)을 갱신해줄 필요도 없을 뿐더러
매 초마다 큐에 가장 앞(front)에 있는 차만 확인해주면 되므로 굉장히 구현이 편리해진다.

=> 다리를 건너는 트럭을 {무게, 도착시간}의 형태로 queue에 저장해서 사용.

! 각 초에서 시뮬레이션 할때 1. 다리에 있는 차를 먼저 내리고 -> 2. 그 다음 새로운 차를 올려야한다.

*/

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int waiting_idx = 0;
    int number_of_waiting_trucks = truck_weights.size();
    int total_weight = 0; // 현재 다리 위에 있는 트럭의 총 무게
    int t = 0;
    int completed = 0;

    queue<ci> trucks_on_bridge; // {weight,arrive_time}

    while (true)
    {

        t++;
        // cout<<"t:"<<t<<"\n";

        ci truck = trucks_on_bridge.front();
        // 1. 내릴 차가 있는지 확인하고 내린다.
        if (truck.second == t)
        {

            // cout<<"트럭내림"<<truck.first<<"\n";

            trucks_on_bridge.pop();
            total_weight -= truck.first;
            completed++;
        }
        if (completed == number_of_waiting_trucks)
        {
            break;
        }

        // 2. 아직 대기중인 차 목록이 있으면 차를 올린다.
        if (waiting_idx < number_of_waiting_trucks)
        {

            int new_truck_weight = truck_weights[waiting_idx];

            if (new_truck_weight + total_weight <= weight)
            {
                trucks_on_bridge.push({new_truck_weight, t + bridge_length});
                // 트럭이 다리를 건너고 내려올 시간 = 현재시간 + 다리 길이

                total_weight += new_truck_weight;
                waiting_idx++;
            }
        }
    }

    return t;
}