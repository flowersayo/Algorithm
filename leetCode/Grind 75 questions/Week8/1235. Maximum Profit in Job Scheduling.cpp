class Solution
{
public:
    static bool cmp(vector<int> &job1, vector<int> &job2)
    {

        return job1[1] < job2[1]; // 끝나는 시간 기준 오름차순
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                      vector<int> &profit)
    {

        map<int, int> dp; // dp[i] : 끝나는 시간 i에서의 최댓값

        vector<vector<int>> jobs;

        for (int i = 0; i < startTime.size(); i++)
        {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end(), cmp);

        int t = 0; // 현재 마지막 시간
        int total_profit = 0;
        for (auto job : jobs)
        {

            int prev_max_profit;

            if (t > job[0])
            { // task 가 겹치면 겹친 대상이 된 task 와 현재
              // 태스크 중 어느것이 더 가치가 큰지를 비교.

                // 현재 job 의 시작시간 이하의 값 중 가장 큰 값 찾기

                auto it = dp.upper_bound(job[0]);

                if (it == dp.begin())
                { // 초과하는 element 가 없음
                    prev_max_profit = 0;
                }
                else
                {
                    it--;
                    prev_max_profit = it->second;
                }

                prev(dp.upper_bound(job[0]))
                    ->second; // 시작시간 초과하는 첫번째 키 ->

                if (prev_max_profit + job[2] >
                    total_profit)
                { // 빼고 넣는게 더 클 때에만
                    total_profit = prev_max_profit + job[2];
                    t = job[1]; // 끝나는 시간 업데이트
                    dp[job[1]] = total_profit;
                }
            }
            else
            { // 안겹치고 독립적이면 무조건 넣음
                total_profit += job[2];
                t = job[1];

                dp[job[1]] = total_profit;
            }
        }

        return total_profit;
    }
};