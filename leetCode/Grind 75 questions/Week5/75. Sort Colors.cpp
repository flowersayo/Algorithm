class Solution
{

    // k(숫자 풀) 가 적을 때 유용한 알고리즘 => 카운팅 소트
    // 시간 복잡도 O(N)

    const int MAX_SIZE = 3;

public:
    void sortColors(vector<int> &nums)
    {

        vector<int> accumulatedSum(MAX_SIZE, 0); // count[i] 까지의 누적합 저장
        vector<int> count(MAX_SIZE, 0);          // count[i] : 숫자 i의 등장 횟수 저장

        for (int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++;
        }

        int idx = 0;
        int number = 0;

        while (number < MAX_SIZE)
        {

            for (int i = 0; i < count[number]; i++)
            {
                nums[idx] = number;
                idx++;

                if (idx == nums.size())
                {
                    break;
                }
            }
            number++;
        }
    }
};