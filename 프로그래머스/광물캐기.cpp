#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

const int INF = 50 * 25;
int min_fatigue = INF;
const int CONSECUTIVE_NUMBER = 5;

// type : 광물의 종류
//  0: 다이아, 1: 철, 2: 돌

map<string, int> typeConversion = {{"diamond", 0}, {"iron", 1}, {"stone", 2}};

// idx부터 연속 cnt개까지의 광물을 type 형태의 곡괭이로 캤을 때 총 피로도
int calcFatigue(int type, int idx, int cnt, vector<string> minerals)
{

    int result = 0;
    for (int i = idx; i < idx + cnt; i++)
    {

        int mineralType = typeConversion[minerals[i]];
        if (mineralType >= type)
        {
            result += 1;
        }
        else
        {
            result += pow(5, type - mineralType);
        }
    }

    return result;
}

// picks : 남아 있는 곡괭이 개수
// minerals : 광물 리스트
// picks_remaindar : 남아있는 곡괭이 개수
void dfs(int idx, int sum, vector<string> minerals, vector<int> picks, int picks_remaindar)
{

    // cout<<"idx :"<<idx<<"sum :"<<sum<<"\n";

    if (idx == ((minerals.size() / 5) + (minerals.size() % 5 ? 1 : 0)) || picks_remaindar == 0) // 모든 광물을 캔 경우 or 곡괭이가 부족한 경우
    {

        min_fatigue = min(sum, min_fatigue); // 최솟값 갱신
        return;
    }

    // 남아 있는 곡괭이들 중 하나 선택

    // cout<<"남아 있는 곡괭이"<<"\n";
    for (int i = 0; i < picks.size(); i++)
    {

        if (picks[i] > 0)
        {

            // idx 에서 시작해서 최대 연속으로 캘 수 있는 값
            int max_consecutive = (minerals.size() - idx * CONSECUTIVE_NUMBER) >= 5 ? 5 : (minerals.size() - idx * CONSECUTIVE_NUMBER);

            int fatigue_sum = calcFatigue(i, idx * CONSECUTIVE_NUMBER, max_consecutive, minerals);
            picks[i]--;
            dfs(idx + 1, sum + fatigue_sum, minerals, picks, picks_remaindar - 1);
            picks[i]++;
        }
    }
}
/**
 * [광물 캐기]
 * https://school.programmers.co.kr/learn/courses/30/lessons/172927
 *
 * dfs 브루트포스 완전 탐색
 * 5개씩 묶고 각각 다이아,철,돌 곡괭이로 캤을 때 경우의 수를 뻗어나가기.
 * => 정해진 조건을 만족하면 최솟값 갱신
 *
 * < 최솟값 갱신 조건 >
 * 1. 모든 광물을 캤을 경우
 * 2. 곡괭이가 모자란 경우
 */
int solution(vector<int> picks, vector<string> minerals)
{

    int picks_remaindar = 0;
    for (int i = 0; i < picks.size(); i++)
    {
        picks_remaindar += picks[i];
    }

    dfs(0, 0, minerals, picks, picks_remaindar);
    return min_fatigue;
}
