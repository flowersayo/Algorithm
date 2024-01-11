class Solution
{
public:
    // sol1. 기존 내풀이
    int longestPalindrome(string s)
    {

        vector<int> alpha(52, 0); // 0~ 25: 소문자, 26 ~ 51: 대문자

        for (char &c : s)
        {

            if (islower(c))
            {
                alpha[c - 'a']++;
            }
            else
            {
                alpha[c - 'A' + 26]++;
            }
        }

        int result = 0;
        int check = 0; // 홀수 숫자가 한번이라도 나올 경우 check=true

        for (int i = 0; i < 52; i++)
        {

            if (alpha[i] % 2 == 0)
            {
                result += alpha[i];
                alpha[i] = 0;
            }
            else
            {
                result += (alpha[i] - 1);
                check = true;
            }
        }

        if (check)
        {
            return result + 1;
        }

        return result;
    }

    // sol2.
    int longestPalindrome(string s)
    {

        int oddCount = 0;

        unordered_map<char, int> ump;

        for (char ch : s)
        {
            ump[ch]++;

            if (ump[ch] % 2 == 1)
            {
                oddCount++;
            }
            else
            {
                oddCount--;
            }
        }

        if (oddCount > 1)
        {
            return s.length() - oddCount + 1;
        }

        return s.length();
    }
};