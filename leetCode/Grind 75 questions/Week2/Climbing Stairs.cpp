class Solution
{
public:
    // sol 1: Recursion -> O(2^n)

    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }

    // sol 2: Memorization
    int climbStairs(int n, unordered_map<int, int> &memo)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        if (memo.find(n) == memo.end())
        {
            memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
        }
        return memo[n];
    }

    int climbStairs(int n)
    {
        unordered_map<int, int> memo;
        return climbStairs(n, memo);
    }

    // sol 3: Tabulation (내 풀이 )
    int climbStairs(int n)
    {

        //  dp[i] : i 를 만드는 경우의 수
        int dp[46] = {
            0,
        };

        dp[1] = 1;
        dp[2] = 2; // 1+1, 2

        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};