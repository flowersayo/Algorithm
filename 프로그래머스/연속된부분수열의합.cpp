#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
[연속된 부분 수열의 합]

=> 같은 위치에서 시작하는 투포인터 활용

? sum == k 를 만족했을때 left 포인터를 옮겨야 하는가 right 포인터를 옮겨야하는가?
=> 상관없다! left 포인터를 옮기도록 하면 합이 커져 다음 턴에 right 포인터가 움직일 것이고,
left 포인터를 옮기도록 하면 합이 작아져 다음 턴에 right 포인터가 움직일 것이다.
=> 이 과정을 간소화해서 sum==k 일때 두 포인터를 동시에 left++ right++ 해도 된다.

*/

typedef pair<int, int> ci;

vector<int> solution(vector<int> sequence, int k)
{
    vector<int> answer(2, 0);

    int left = 0;
    int right = 0;
    int sum = sequence[0];
    int len = sequence.size();

    vector<ci> candidates;

    int min_len = len;
    while (left <= right && right < len)
    {

        if (sum < k)
        { // sum 이 아직 작으면 범위를 넓힘

            right++;
            sum += sequence[right];
        }
        else if (sum >= k)
        { // sum이 크면 범위를 좁힘
            if (sum == k)
            {

                int len = right - left;

                if (len < min_len)
                {
                    min_len = len; // 갱신
                    answer[0] = left;
                    answer[1] = right;
                }
                right++;
                sum += sequence[right]; // 동시에 갱신 (루프 1회 줄일 수 있음)
            }
            sum -= sequence[left];
            left++;
        }
    }

    return answer;
}