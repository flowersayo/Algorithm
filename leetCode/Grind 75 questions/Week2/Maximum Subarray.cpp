class Solution
{
public:
    const int INF = 10000 * 100000;

    int maxSubArray(vector<int> &nums)
    {

        int max_sum = -INF;

        int current_sum = 0;
        // current_sum 이 지금 숫자보다 작거나 음수이면 초기화 한다.
        // a,b,c... 를 더해서 -10이고, d가 0 이라고 치면 a,b,c..  를 누적해서 갖고있어봤자
        // 음수만 더 누적될 뿐이기 때문이다. ( 없는게 전체 합 증가에 도움이 된다.)

        // a,b,c...  3
        // d 5 일 경우에도
        // abc 를 포기하고 d를 가져가나..?
        // 1 1 1 5

        for (int i = 0; i < nums.size(); i++)
        {
            current_sum = max(current_sum + nums[i], nums[i]); // current_sum<0 이면 nums[i]로 초기화
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};