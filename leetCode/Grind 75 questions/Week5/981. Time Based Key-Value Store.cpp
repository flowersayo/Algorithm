class TimeMap
{
public:
    unordered_map<string, vector<pair<string, int>>> m;

    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        m[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp)
    {

        if (m.find(key) != m.end())
        {

            // vector<pair<string, int>> v = it->second; -> 일일히 복제하면 O(N) 시간초과

            // v 목록 중 timestamp_prev <= timestamp 를 만족하는 최댓값 리턴
            // 시간 복잡도 O(N)로 일일히 갱신하면 시간 초과남. 여기서 시간을
            // 줄여야함. 그런데 이분탐색 쓰려면 정렬이 되어있어야 하는데..
            // 모든 timestamp 값이 strictly increasing 이라 애초에 정렬상태!

            int left = 0, right = m[key].size() - 1;

            while (left <= right)
            {

                int mid = (left + right) / 2;
                if (m[key][mid].second < timestamp)
                {
                    left = mid + 1;
                }
                else if (m[key][mid].second > timestamp)
                {
                    right = mid - 1;
                }
                else
                {                             // target 을 찾았다면
                    return m[key][mid].first; // 그 자체가 최댓값
                }
            }

            if (right >= 0)
            {
                return m[key][right].first;
            }
        }

        return ""; // 0 보다 작으면 timestamp 이하를 만족하는 값이 없는 경우 -> "" 리턴
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */