class Solution
{
public:
    const int INF = 10001;
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        int start = newInterval[0], end = newInterval[1];
        int start_idx = -1, end_idx = -1;

        bool doesFindFirstOverlapPoint = false;

        for (int i = 0; i < intervals.size(); i++)
        {

            int s = intervals[i][0];
            int e = intervals[i][1];

            // 사이 사이 오버랩 되는 지점
            if (i + 1 < intervals.size() && intervals[i][1] < newInterval[0] && intervals[i + 1][0] > newInterval[1])
            {

                intervals.insert(intervals.begin() + i + 1, {start, end});
                return intervals;
            }

            // s ~ e 사이에 overlap 되는 값이 있는 지 확인
            for (int j = s; j <= e; j++)
            {

                if (!doesFindFirstOverlapPoint && j >= newInterval[0] && j <= newInterval[1])
                { // 처음으로 오버랩 되는 지점

                    start_idx = i;
                    start = min(s, newInterval[0]);
                    doesFindFirstOverlapPoint = true;
                }

                if (j >= newInterval[0] && j <= newInterval[1])
                { // 마지막으로 오버랩 되는 지점 (계속 갱신)

                    end_idx = i + 1;
                    end = max(e, newInterval[1]);
                }
            }
        }

        vector<int> merged = {start, end};

        if (start_idx == -1 && end_idx == -1)
        { // overlap 되는 곳을 찾지 못한 경우

            if (intervals.size() == 0 || newInterval[0] < intervals[0][0])
            { // 맨 처음 구간 독립
                intervals.insert(intervals.begin(), merged);
            }
            else if (newInterval[0] > intervals[intervals.size() - 1][1])
            { // 맨 마지막 구간 독립
                intervals.insert(intervals.end(), merged);
            }
        }
        else
        {
            intervals.erase(intervals.begin() + start_idx, intervals.begin() + end_idx);
            intervals.insert(intervals.begin() + start_idx, merged);
        }

        return intervals;
    }
};