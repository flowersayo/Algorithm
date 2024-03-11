#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int INF = 987654321;

// 문자열을 1 ~ s.size()개 단위로 자른다.
// 각각의 단위로 잘라보고 압축하여 표현한 문자열 중 가장 짧은 길이 갱신

int solution(string s)
{
    int answer = INF;

    for (int i = 1; i <= s.length(); i++)
    { // i: 자르는 기준 단위 (문자열 길이)

        // 1. 문자열 토큰으로 분리하기
        vector<string> tokens;
        for (int j = 0; j < s.length(); j += i)
        {
            tokens.push_back(s.substr(j, i)); // 지정된 카운트가 시작 지점으로부터 남은 문자열의 길이를          초과하면 남은 부분까지만 반환
        }

        // 2. 토큰을 순회하면서 연속된 패턴 개수 카운트하면서 압축된 문자열 완성

        int cnt = 1;
        string pattern = tokens[0];
        string compression = ""; // 압축된 전체 문자열

        for (int j = 1; j < tokens.size(); j++)
        {
            if (pattern == tokens[j])
            { // 기존 패턴과 일치하면
                cnt++;
            }
            else
            { // 일치하지 않으면

                if (cnt == 1)
                {
                    compression += pattern; // 숫자 1은 생략
                }
                else
                {
                    compression += (to_string(cnt) + pattern);
                }

                pattern = tokens[j]; // 패턴 초기화
                cnt = 1;
            }
        }

        if (cnt == 1)
        {
            compression += pattern; // 숫자 1은 생략
        }
        {
            else compression += (to_string(cnt) + pattern);
        }

        int len = compression.size();
        answer = min(answer, len);
    }

    return answer;
}
x