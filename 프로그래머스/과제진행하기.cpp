#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <stack>

using namespace std;

typedef pair<string, int> si;

/**
[과제 진행하기]
https://school.programmers.co.kr/learn/courses/30/lessons/176962

기존 코드인 stopped.playtime -= time_left;  가 복제본을 변경하여
실제 playtime 이 변경되지 않는 이슈가 있었다.

=> stopped.top().playtime -= time_left; 으로 수정함으로서 해결!

*/

struct Plan
{

    string name;
    int start;    // 시작 시간을 자정기준 초로 환산
    int playtime; // 남은 시간 (단위 : 분)
};

bool cmp(vector<string> plan_a, vector<string> plan_b)
{

    return plan_a[1] < plan_b[1]; // 시간 오름차순
}

vector<string> work(queue<Plan> todo)
{

    stack<Plan> stopped;      // 중간에 멈춘 과제들
    vector<string> completed; // 완료한 과제들

    while (todo.size() >= 2)
    {

        Plan current = todo.front();
        todo.pop();

        Plan next = todo.front(); // 다음에 해야 할 과제

        int btn_time = next.start - current.start;

        if (current.playtime <= btn_time)
        { // 끝내면

            completed.push_back(current.name);
            int time_left = btn_time - current.playtime;

            // 남아 있는 시간 활용해서 남은 과제 처리하기
            while (time_left > 0 && !stopped.empty())
            {

                Plan stop = stopped.top();

                if (time_left >= stop.playtime)
                { // 남은 시간동안 끝낼 수 있는 과제이면
                    completed.push_back(stop.name);
                    time_left -= stop.playtime;
                    stopped.pop();
                }
                else
                { // 남은 시간동안 해서 못 끝내면
                    stopped.top().playtime -= time_left;

                    break;
                }
            }
        }
        else
        { // 여유 시간이 없으면 바로 다음 과제하러

            current.playtime -= btn_time;
            stopped.push(current);
        }
    }

    // 마지막 과제
    completed.push_back(todo.front().name);

    // stopped 에 남아있는 과제 작업 처리하기
    while (!stopped.empty())
    {

        Plan work = stopped.top();
        completed.push_back(work.name);
        stopped.pop();
    }

    return completed;
}
int time_to_minutes(string time)
{

    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));

    return hour * 60 + minute;
}
vector<string> solution(vector<vector<string>> plans)
{

    sort(plans.begin(), plans.end(), cmp);

    queue<Plan> todo;

    for (int i = 0; i < plans.size(); i++)
    {

        int start_to_minutes = time_to_minutes(plans[i][1]);
        int playtime_to_minutes = stoi(plans[i][2]);

        Plan plan = {plans[i][0], start_to_minutes, playtime_to_minutes};

        todo.push(plan);
    }

    vector<string> answer = work(todo);
    return answer;
}