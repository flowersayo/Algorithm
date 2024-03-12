#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

typedef pair<int, int> ci;

int solution(vector<int> topping)
{
    int answer = 0;

    map<int, int> left;  // 기준선 기준 왼쪽 { 토핑 종류, 개수 }
    map<int, int> right; // 기준선 기준 오른쪽 { 토핑 종류, 개수 }

    for (int i = 0; i < topping.size(); i++)
    {
        right[topping[i]]++;
    }

    for (int i = 0; i < topping.size(); i++)
    { // i번째와 i+1 사이에 기준선이 생긴다면

        right[topping[i]]--;
        left[topping[i]]++;

        if (right[topping[i]] == 0)
        {
            right.erase(topping[i]);
        }

        if (left.size() == right.size())
        {
            answer++;
        }
    }

    return answer;
}