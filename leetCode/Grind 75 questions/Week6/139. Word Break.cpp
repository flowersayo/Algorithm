#include <algorithm>

class Solution
{
public:
    // 1. DP solution
    // dp[i] : index i-1 로 끝나는 단어가 있다면 true
    //  i-1 로 끝나는 조각단어 모음이 있는지 확인하려면 j=i-1 부터 j=0 까지 j-- 하면서 0~j,j~i 로 나누어지는 구간이 있는지 확인하면 된다.
    // 이때, 단어 길이 만큼만 j를 줄이면 되므로 maximum length 저장하고 j=i-1 부터 j=max_len-1 까지 수행한다.

    bool wordBreak(string s, vector<string> &wordDict)
    {

        int max_len = -1;
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 0; i < wordDict.size(); i++)
        {
            int len = wordDict[i].size();
            max_len = max(max_len, len);
        }

        for (int i = 1; i <= n; i++)
        {

            for (int j = i - 1; j >= max(i - max_len, 0); j--)
            {
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
                { // ~ j , j
                    dp[i] = true;
                    break; // 이미 i로 끝나는 경우가 있다고 판명난 경우
                }
            }
        }
        return dp[n];
    }
};