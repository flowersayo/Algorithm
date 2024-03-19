class Solution
{
public:
    string longestPalindrome(string s)
    {

        int len = s.length();

        int dp[1001][1001] = {
            false,
        }; // i ~ j 까지 문자열이 팰린드롬인지

        for (int i = 0; i < len; i++)
        {
            dp[i][i] = true;
        }

        int start_idx = 0;
        int cnt = 1;
        for (int j = 0; j < len; j++)
        { // 단어의 끝
            for (int i = 0; i <= j; i++)
            { // 단어의 시작

                if (j - i == 0)
                { // 길이가 1이면
                    dp[i][j] = true;
                }
                else if (j - i == 1)
                { // 길이가 2이면

                    dp[i][j] = s[i] == s[j];
                }
                else
                {                                                  // 3이상이면
                    dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]); // i-1 j-1 이 팰린드롬이고 ~ i==j
                }

                // cout<<s.substr(i,j-i+1)<<" "<<dp[i][j]<<"\n";

                if (dp[i][j] && (cnt < j - i + 1))
                {
                    start_idx = i;
                    cnt = j - i + 1;
                }
            }
        }

        return s.substr(start_idx, cnt);
    }
};