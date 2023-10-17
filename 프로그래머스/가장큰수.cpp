#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
[가장 큰 수]

https://school.programmers.co.kr/learn/courses/30/lessons/42746

=> 맨 앞자리 수가 큰 순으로 정렬

*/

int DIGITS = 0; // 자릿수

bool cmp(int a, int b)
{

    string a_b = to_string(a) + to_string(b);
    string b_a = to_string(b) + to_string(a);
    return a_b > b_a; // 수를 합쳤을 때 더 큰 순
}
string solution(vector<int> numbers)
{

    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);

    for (int i = 0; i < numbers.size(); i++)
    {
        answer += to_string(numbers[i]);
    }
    if (numbers[0] == 0)
    {
        return "0";
    }
    return answer;
}