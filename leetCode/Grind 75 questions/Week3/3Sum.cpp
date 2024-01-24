class Solution
{
public:
    // 백준 세용액 문제와 비슷!

    void fixedSum(int fixed, int start, int end, vector<int> &nums, vector<vector<int>> &answer)
    {

        int left = start;
        int right = end;

        while (left < right)
        {

            if (nums[left] + nums[right] + fixed < 0)
            {
                left++;
            }
            else if (nums[left] + nums[right] + fixed > 0)
            {
                right--;
            }
            else
            {

                vector<int> new_set = {fixed, nums[left], nums[right]};
                answer.push_back(new_set);

                // 같은 값이 아닐때까지 포인터 옮기기
                while (left < right && nums[left] == new_set[1])
                {
                    left++;
                }

                while (left < right && nums[right] == new_set[2])
                {
                    right--;
                }
            }
        }
    }
    // 중복 되는 원소를 없애는 방법? -> 중복 원소를 발견하면 건너뛴다.

    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());

        // 중복된 원소 삭제
        // nums.erase(unique(nums.begin(), nums.end()), nums.end());

        for (int i = 0; i <= nums.size() - 1; i++)
        {

            if (i && nums[i - 1] == nums[i])
            {             // 같은 값일 경우
                continue; // 넘어가기
            }

            fixedSum(nums[i], i + 1, nums.size() - 1, nums, answer);
        }

        return answer;
    }
};