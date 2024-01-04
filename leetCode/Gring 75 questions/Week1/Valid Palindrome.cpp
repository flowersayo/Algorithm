#include <cctype>

using namespace std;

class Solution
{
public:
    string removeNonAlphanumeric(string s)
    {

        string new_string = "";
        for (char &c : s)
        {
            c = tolower(c);
            if (isdigit(c) || (c >= 'a' && c <= 'z'))
            {
                new_string += c;
            }
        }

        return new_string;
    }

    bool isPalindrome(string s)
    {

        string pure_string = removeNonAlphanumeric(s);

        int len = pure_string.length();
        for (int i = 0; i < len / 2; i++)
        {
            if (pure_string[i] != pure_string[len - 1 - i])
            {
                return false;
            }
        }

        return true;
    }

    // ver 2. string 을 요구된 형태로 다듬을 필요 없이 바로 투포인터로 풀이

    bool isPalindrome(string s)
    {

        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {

            if (!isalnum(s[left]))
            {
                left++; // 넘어간다.
                continue;
            }

            if (!isalnum(s[right]))
            {
                right--; // 넘어간다.
                continue;
            }

            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }

        return true;
    }
};