class Solution
{
public:
    // sol1. 재귀 탐색 : 각 원소마다 넣을지 말지 선택
    // 1 <= nums.length <= 10 이므로 최대 2^10 가지의 부분집합이 존재할 수 있음
    // -> 재귀로 처리해도 TLE 안남
    vector<vector<int>> answer;
    vector<int> arr;

    void subset(int idx, vector<int> &nums, vector<int> arr)
    {

        if (idx == nums.size())
        {
            return;
        }

        // 1. nums[idx] 를 넣지 않는 경우
        subset(idx + 1, nums, arr);

        arr.push_back(nums[idx]);
        answer.push_back(arr);

        // 2. nums[idx] 를 넣는 경우
        subset(idx + 1, nums, arr);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        arr.assign(nums.size(), 0);
        answer.push_back({});
        subset(0, nums, {});
        return answer;
    }

    // sol2. 비트마스킹
    vector<vector<int>> subsets(vector<int> &nums)
    {

        int n = nums.size();
        int k = 1 << n; // 2^n
        vector<vector<int>> answer(k);

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {

                /*
               i&(1<<j) 와 (i >> j) & 1 의 차이
                i & (1 << j): 이 연산은 i의 비트 중에서 j번째 비트만을 추출합니다. 이를 위해 1 << j는 j번째 비트만이 1이고 나머지는 0인 값을 만듭니다. 그 후 i와 AND 연산을 수행하여 i의 해당 비트를 추출합니다. 이는 시프트 연산과 AND 연산 두 가지 연산을 수행하므로 비교적 빠른 속도를 보입니다.
                (i >> j) & 1: 이 연산은 i를 j만큼 오른쪽으로 시프트한 후, 가장 오른쪽 비트만을 추출합니다. 즉, i의 j번째 비트를 추출하는 것입니다. 이는 시프트 연산과 AND 연산을 수행하므로 (i >> j) & 1 연산이 좀 더 복잡하며, 따라서 더 오래 걸릴 가능성이 있습니다.
                */
                if ((i >> j) & 1)
                { // i의 j번째 비트가 1이라면
                    answer[i].push_back(nums[j]);
                }
            }
        }

        return answer;
    }
};
