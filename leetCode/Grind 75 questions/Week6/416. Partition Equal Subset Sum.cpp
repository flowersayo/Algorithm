class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {

        // 우리는 주어진 집합에서 합이 전체합/2 가 되는 부분집합을 구하면 된다.
        // 두개의 집합으로 분할하는 경우의 수, 부분집합의 경우의 수는 2^(n-1) -2
        // (공집합 제외)
        //  이를 recursion 으로 구현하려 하면 TLE
        // 따라서 dp 를 활용한다.
        // idea! 원소 합이 k 가 되는 경우의 수가 있다는 것은,
        // 원소 합이 k-n 인 경우가 있고 거기서 원소 중 하나의 값인 n 을 더해서
        // k를 만들 수 있다는 것이다. 따라서 dp[i] = dp[i] || dp[i-x] (x는 원소
        // 중 하나) 라는 식을 유도할 수 있다.

        int total_sum = 0;

        for (auto num : nums)
        {
            total_sum += num;
        }

        if (total_sum % 2)
        { // 홀수일경우
            return false;
        }

        int half_sum = total_sum / 2;

        vector<bool> dp(half_sum + 1, false);

        dp[0] = true;

        for (auto num : nums)
        {
            for (int i = half_sum; i >= num; i--)
            { // i :  target sum

                dp[i] = dp[i] || dp[i - num]; // 이미 다른 숫자들로 조합해서 만들 수
                                              // 있거나 지금 수를 뺀 경우의 수에
                                              // 지금 수를 더해서 만들 수 있거나
            }
        }

        return dp[half_sum];
    }
};