#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    stack<int> st;

    // i : 작업 번호 push. 앞에 있는게 맨 위에 오도록
    for (int i = progresses.size() - 1; i >= 0; i--)
    {
        st.push(i);
    }

    while (!st.empty())
    { // 작업이 남아 있을 때까지

        vector<bool> completed(progresses.size(), false);

        // 매 페이즈마다 speed 만큼 개발 진척
        for (int i = 0; i < progresses.size(); i++)
        {

            if (completed[i])
            { // 이미 완료된 job 이라면
                continue;
            }

            progresses[i] += speeds[i];

            if (progresses[i] >= 100)
            {
                completed[i] = true;
            }
        }

        // 매 페이즈마다 배포될 수 있는 기능의 개수 확인
        int cnt = 0;
        while (!st.empty())
        {
            int work_num = st.top();

            if (completed[work_num])
            {
                cnt++;
                st.pop(); // top 제거
            }
            else
            {
                break;
            }
        }

        if (cnt != 0)
        {
            answer.push_back(cnt);
        }
    }

    return answer;
}