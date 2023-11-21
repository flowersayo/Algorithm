#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

// 끝나는게 이른 순으로 정렬

bool cmp(ci a, ci b)
{

    if (a.second != b.second)
    {                               // 끝나는 시간이 다르다면
        return a.second < b.second; // 일찍 끝나는거부터
    }

    return a.first < b.first;
}
int main()
{

    int n;

    cin >> n;

    vector<ci> lectures(n);

    for (int i = 0; i < n; i++)
    {
        cin >> lectures[i].first >> lectures[i].second;
    }

    sort(lectures.begin(), lectures.end(), cmp);

    int last = 0; // 마지막 강의의 종료 시간
    int cnt = 0;  // 최대 강의 수
    for (int i = 0; i < lectures.size(); i++)
    {

        if (last <= lectures[i].first)
        {
            last = lectures[i].second;
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}