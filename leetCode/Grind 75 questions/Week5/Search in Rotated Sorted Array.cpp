class Solution
{
public:
    // mid 를 기점으로 정상적으로 오름차순 정렬을 이루고 있는 곳을 찾고
    // 그 구간 내에 target 이 속하는지 확인한다.
    // 예를 들어 4 5 6 7 8 9(mid) 10 0 1 2 3 같은 상태일 때,
    // mid 와 r 을 비교해서 왼쪽, 오른쪽 중 어느곳에 pivot 이 존재하는지 알아낼 수 있다.
    // 이를 바탕으로 왼쪽에 pivot 이 없다는 사실을 확인하고(= 오름차순이 꺾이는 지점이 없음)
    // left 와 mid 값 사이에 target 이 존재하는지 여부를 확인한 다음
    // 만일 그 범위에 해당하면 왼쪽 영역을 탐색하는 식으로 탐색을 진행한다.

    int binary_search(vector<int> &nums, int target)
    {

        int SIZE = nums.size();

        int l = 0;
        int r = SIZE - 1;

        while (l <= r)
        {

            int m = (l + r) / 2;

            if (nums[m] == target)
            { // 찾은 경우
                return m;
            }

            else if (nums[m] < nums[r])
            { // 오른쪽은 오름차순 정렬

                if (target > nums[m] && target <= nums[r])
                {
                    l = m + 1; // 오른쪽 영역 탐색
                }
                else
                { // target> nums[r] ||target < nums[m]
                    r = m - 1;
                }
            }

            else
            { // 오른쪽에 피봇 존재
                if (target < nums[m] && target >= nums[l])
                {              //  -> 왼쪽 영역에 target 이 존재할 경우
                    r = m - 1; // 왼쪽 영역 탐색
                }
                else
                {              // target > nums[m] || target < nums[l]
                    l = m + 1; // 오른쪽 영역 탐색
                }
            }
        }

        return -1;
    }
    int search(vector<int> &nums, int target)
    {

        return binary_search(nums, target);
    }
};