#include <iostream>
#include <bitset>

using namespace std;

//  N <= 10, M <= 50
int N, M; // 기타 개수, 곡 개수

// 주어진 정수 x에서 비트 1이 몇개인지 세는 함수

int bit_cnt(long long x, int size)
{
    int ret = 0;

    for (int i = 0; i < size; i++)
    {

        // 방법 1. 0001, 0010, 0100, 1000 과 AND 연산을 통하여 특정 자리 비트가 1인지 확인
        // 단, 이 경우에는 결과 값이 나머지 비트는 0이고 우리가 집중하는 비트의 값이 1인 형태로 나타나므로
        // 완전히 0000 인 경우에 i번째 자리가 0이었다고 판단할 수 있고, 0이 아닌 값인 1000, 0010 같은 경우는 모두 기존 비트가 1이었다고 판단할 수 있다.
        /*
        if ((x & (1 << i)) == 0)
        {
            continue;i
        }

        ret++;
        */

        // 방법 2. 원본 비트를 오른쪽으로 밀어서 항상 맨 오른쪽에 비교 대상이 오도록하는 법
        // 결과 값이 0 or 1로 딱 나누어 떨어져 연산결과가 직관적이다.

        if ((x >> i) & 1)
        {
            ret++;
        }
    }

    return ret;
}

int main()
{

    cin >> N >> M;

    int min_guitar_cnt = -1; // 최소 기타 개수
    int max_song_cnt = 0;    // 가장 많이 연주할 수 있는 곡 개수

    string name, tmp;
    long long state[10] = {
        0,
    }; // i번째 기타가 연주할 수 있는 곡의 개수를 비트로 저장

    // 각 기타의 연주 상태를 입력
    for (int i = 0; i < N; i++)
    {
        cin >> name >> tmp;

        for (int j = 0; j < M; j++) // "YYYNN" 의 맨 오른쪽 자리부터 비트 마스킹
        {
            state[i] = (state[i] << 1) | (tmp[j] == 'Y'); // 맨 오른쪽 비트에 결과값 마스킹
                                                          // 왼쪽 shift (맨 오른쪽 비트 비워두기)
        }

        //  bitset<5> binary(state[i]);
        // cout << " " << binary << "\n";
    }

    // 2^N가지 모든 경우의 수(조합) 구하기
    for (int i = 0; i < (1 << N); i++)
    { // i : 0000, 0001, 0010, 0011 , ... , 1111

        long long comb = 0; // 선택된 모든 기타들에서 가능한 곡목록을 조합한 결과

        // 선택된 기타들에 대해 곡 목록 합산
        for (int j = 0; j < N; j++)
        {

            // 1 이 정수형 32 bit 로 인지되어 그 이상에 대해 오버플로우가 발생하는 것을 방지
            if ((i & (1LL << j)) == 0) // j번째 기타가 선택되었는지(i의 j번째 비트가 1인지) 확인
            {
                continue;
            }

            comb |= state[j]; // 가능한 곡 목록에 추가 (OR 연산)
        }

        int song_cnt = bit_cnt(comb, M); // 연주할 수 있는 곡 갯수
        int guitar_cnt = bit_cnt(i, N);  // 총 기타 갯수

        // 연주할 수 있는 곡 갯수가  더 많은 경우
        if (song_cnt > max_song_cnt)
        {

            max_song_cnt = song_cnt;
            min_guitar_cnt = guitar_cnt; // 최소 기타 개수 업데이트
        }
        // 연주할 수 있는 곡 갯수가 같은데 사용한 기타 개수가 더 작은 경우
        // (-1 일 경우는 조건을 만족하는 guitar_cnt 이 존재할 수 없다. 본 조건문은 반드시 위 조건문이 한번 이상 시행되고 난 이후에 조건이 만족될 수 있다.)
        else if (song_cnt == max_song_cnt && guitar_cnt < min_guitar_cnt)
        {
            min_guitar_cnt = guitar_cnt; // 최소 기타 개수 업데이트
        }
    }

    cout << min_guitar_cnt;

    return 0;
}