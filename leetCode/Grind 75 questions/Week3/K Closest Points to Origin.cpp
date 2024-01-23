class Solution
{
public:
    typedef pair<long double, int> ldi;

    // sol 1: 정렬
    // O(NlogN)
    // 단 : 실시간으로 추가 되는 점 들에 대해서(online)는 매번 새로 계산을 수행하므로 비효율적

    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {

        vector<vector<int>> answer;
        vector<ldi> dist;

        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            long double dist_from_origin = sqrt(x * x + y * y); // 정확하게 계산하지 못하게 되는 경우?

            dist.push_back({dist_from_origin, i});
        }

        sort(dist.begin(), dist.end());

        for (int i = 0; i < k; i++)
        {

            int idx = dist[i].second;

            answer.push_back(points[idx]);
        }

        return answer;
    }

    // sol2 : 사이즈가 k인 max heap 사용
    // n(점 개수) * logK(max heap에 삽입하는데 걸리는 시간)
    // => 동적으로 점을 추가해서 계산하기 좋음

    // sol3: quick select
    // quick sort 에서 pivot 을 기준으로 왼쪽 값은 pivot 보다 작고, 오른쪽 값은 pivot 보다 커진다라는 점을 활용.
    // O(N) * k번째가 피봇이 되기까지 걸리는 시간
    // Q. 근데 그러려면 k번째로 큰 수를 pivot 으로 지정할 수 있어야하는데?
    // A. k번째가 pivot이 될 때 까지 여러번 quick select 를 돌린다.
};