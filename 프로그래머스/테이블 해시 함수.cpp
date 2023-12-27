#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * [테이블 해시 함수]
 * https://school.programmers.co.kr/learn/courses/30/lessons/147354
 *
 * 문제만 잘 이해하면 어렵지 않게 풀 수 있는 문제
 * Tip : C++ 의 XOR 연산자인 ^ 활용하기!
 *
 */

int idx; // 정렬 기준 인덱스

bool cmp(vector<int> tuple1, vector<int> tuple2)
{

    if (tuple1[idx] != tuple2[idx])
    {
        return tuple1[idx] < tuple2[idx]; // 오름차순
    }

    return tuple1[0] > tuple2[0]; // 내림차순
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{

    idx = col - 1;

    // col 번째 원소를 기준으로 동적으로 내림차순 정렬
    sort(data.begin(), data.end(), cmp);

    vector<int> S;
    for (int i = row_begin - 1; i < row_end; i++)
    {

        int sum = 0;
        for (int j = 0; j < data[i].size(); j++)
        {
            sum += data[i][j] % (i + 1);
        }

        S.push_back(sum);
    }

    int answer = S[0];

    for (int i = 1; i < S.size(); i++)
    {
        answer = answer ^ S[i];
    }

    return answer;
}