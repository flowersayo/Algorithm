#include <climits>

typedef pair<string, int> si;

class Solution
{
public:
    string ignoreLeadingWhitespace(string s)
    { // 맨 앞에 있는 공백만 제거

        int start_idx = 0;

        while (s[start_idx] == ' ')
        {
            start_idx++;
        }
        return s.substr(start_idx);
    }

    si readNumberToken(string str_trimmed)
    { // number token 찾기
        si result;
        int sign = 1;
        int start = 0;

        if (str_trimmed[0] == '-' || str_trimmed[0] == '+')
        {
            if (str_trimmed[0] == '-')
            {
                sign = 0;
            }
            start++; // 부호 제외 시작지점
        }
        // "+0123"
        // 맨 앞자리에 있는 0은 제거
        while (str_trimmed[start] == '0')
        {
            start++;
        }

        int last = start;

        // non-digit(특수문자나 공백) 이 나올때까지
        while (last < str_trimmed.length())
        {

            if (str_trimmed[last] < '0' ||
                str_trimmed[last] > '9')
            { // non-digit 이라면 (이 조건식에 공백도 포함)
                break;
            }

            last++;
        }

        string number_token = str_trimmed.substr(start, last - start);

        result = {number_token, sign};

        return result;
    }

    long long convertDigitsToInteger(int sign,
                                     string digit)
    { // 순수한 digit 만 들어있는 문자열

        long long sum = 0;    // 각 자릿수를 더함
        long long factor = 1; // 각 자릿수별 가중치
                              // 더한 값 계산하기
        for (int i = digit.size() - 1; i >= 0; i--)
        {

            if (factor > INT_MAX)
            { // 오버플로우 방지
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            long long n = digit[i] - '0'; // char -> int

            if (sign == 0)
            {
                sum -= (factor * n);
            }
            else
            {
                sum += (factor * n);
            }

            factor *= 10;
        }
        return sum;
    }
    int myAtoi(string s)
    {

        string trimmed_str = ignoreLeadingWhitespace(s);
        si result = readNumberToken(trimmed_str);
        string number_token = result.first;
        int sign = result.second;
        if (trimmed_str == "")
        { // 공백과 기호 이후 숫자가 없는 경우 ex)"   -a","   - ","   -"
            return 0;
        }

        long long s_to_interger = convertDigitsToInteger(sign, number_token);

        if (s_to_interger > INT_MAX)
        {
            return INT_MAX;
        }
        if (s_to_interger < INT_MIN)
        {
            return INT_MIN;
        }

        return s_to_interger;
    }
};