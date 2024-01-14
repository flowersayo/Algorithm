class Solution
{
public:
    string padStart(string str, int target_length, char c)
    {

        int length = str.length();
        for (int i = 0; i < target_length - length; i++)
        { // str.length()가 동적으로 변할 수 있음에 유의!
            str = c + str;
        }

        return str;
    }

    string addBinary(string a, string b)
    {

        int long_length = max(a.length(), b.length());

        if (a.length() < b.length())
        {
            a = padStart(a, long_length, '0');
        }
        else
        {
            b = padStart(b, long_length, '0');
        }

        string answer = "";
        bool carry = 0; //  carry 가 2이상 발생하는 경우 없음
        int sum = 0;

         for (int i = long_length - 1; i >= 0; i--)
        {

            sum = carry + (a[i] - '0') + (b[i] - '0');
            cout << sum << "\n";

            carry = sum / 2;

            sum %= 2;
            answer = (char)(sum + '0') + answer;
        }

        if (carry)
        {
            return '1' + answer;
        }

        return answer;
    }
};