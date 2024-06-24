#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// n/2개의 선택된 다이스 굴리기
void roll(int idx, int sum, vector<int> &selected, vector<vector<int>> &dice, vector<int> &sums)
{

    if (idx == selected.size())
    {
        sums.push_back(sum);
        return;
    }

    // 여섯 개의 눈 중에 하나 고르기
    for (int i = 0; i < 6; i++)
    {

        sum += dice[selected[idx] - 1][i];
        roll(idx + 1, sum, selected, dice, sums);
        sum -= dice[selected[idx] - 1][i];
    }
}
vector<int> solution(vector<vector<int>> dice)
{
    vector<int> answer;

    const int n = dice.size();
    const int SIZE_OF_DICE = 6;

    int max_win = -1;

    // 주사위 n개 중에서 절반을 선택
    vector<bool> comb(n, 0);
    // 마지막 n/2개를 1로 (오름차순 정렬)
    fill(comb.end() - n / 2, comb.end(), 1);

    do
    {
        // 각각이 선택된 주사위 목록
        vector<int> a_selected;
        vector<int> b_selected;

        for (int i = 0; i < comb.size(); i++)
        {

            if (comb[i])
            {
                a_selected.push_back(i + 1);
            }
            else
            {
                b_selected.push_back(i + 1);
            }
        }

        vector<int> a_sums = {}; // 최대 6^5 7776
        vector<int> b_sums = {}; // 최대 6^5 7776

        roll(0, 0, a_selected, dice, a_sums);
        roll(0, 0, b_selected, dice, b_sums);

        int a_win = 0;

        sort(a_sums.begin(), a_sums.end());
        sort(b_sums.begin(), b_sums.end());

        int comb_num = a_sums.size();

        // 하나의 a sum 결과에 대해 나머지 b 들 비교
        for (int idx_a = 0; idx_a < a_sums.size(); idx_a++)
        {

            // 이분 탐색으로 처음으로 특정 값 초과하는 지점
            int idx = lower_bound(b_sums.begin(), b_sums.end(), a_sums[idx_a]) - b_sums.begin();
            a_win += idx;
        }

        if (max_win < a_win)
        {
            answer = a_selected;
            max_win = a_win;
        }

    } while (next_permutation(comb.begin(), comb.end())); // 주사위 n개 중 n/2개 선택

    return answer;
}