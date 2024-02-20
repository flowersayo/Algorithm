class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> answer;

        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0], end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {

            if (intervals[i][0] <= end)
            {                                    // 그 다음 지점의 시작지점이 현재 영역에 걸친다면
                end = max(intervals[i][1], end); // 하나로 합치기
            }
            else
            { // 그렇지 않고 띄어져 있으면
                answer.push_back({start, end});

                // 새로운 구간 갱신
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        answer.push_back({start, end});

        return answer;
    }
};