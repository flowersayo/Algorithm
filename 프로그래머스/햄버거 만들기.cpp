#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int makeBurger(vector<int> ingredients)
{

    vector<int> v = {-1};
    int cnt = 0;
    for (auto ingredient : ingredients)
    {

        if (v.back() == 1 && ingredient == 2)
        {
            v.back() = 12;
        }
        else if (v.back() == 12 && ingredient == 3)
        {
            v.back() = 123;
        }
        else if (v.back() == 123 && ingredient == 1)
        {
            v.pop_back(); // 햄버거 제거
            cnt++;
        }
        else
        {
            v.push_back(ingredient);
        }
    }
    return cnt;
}
/**
[햄버거 만들기]
https://school.programmers.co.kr/learn/courses/30/lessons/133502?language=cpp#

스택에 재료를 하나씩 넣으면서 마지막 4개 재료가 빵-야채-고기-빵을 이루면
스택에서 제거한다. 이 때 새로운 재료를 넣을 때마다 마지막 4개를 확인해주는 것은 비효율적이므로
햄버거 순서 조건을 만족하면 누적해서 배열에 관리해준다.

*/
int solution(vector<int> ingredient)
{
    int answer = makeBurger(ingredient);

    return answer;
}