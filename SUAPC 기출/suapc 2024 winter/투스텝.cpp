#include <iostream>

using namespace std;

const int DIVISOR = 26;

string encode(long long int n) // n을 25진수 알파벳으로 암호화. z는 빈자리
{
    string str = "";

    do
    {
        int mod = n % DIVISOR;
        n = n / DIVISOR;

        char c = 'a' + mod; // a = 0 이 되도록
        str = c + str;

    } while (n != 0);

    // 13 자리 꽉 채우기
    while (str.size() < 13)
    {
        str = 'a' + str;
    }

    return str;
}

long long int decode(string str)
{

    long long int sum = 0;
    long long int factor = 1;

    for (int i = str.size() - 1; i >= 0; i--)
    {
        sum += ((str[i] - 'a')) * factor;
        factor *= 26;
    }

    return sum;
}

int main()
{

    int t;

    cin >> t;

    if (t == 1)
    {
        long long int a, b;
        cin >> a >> b;

        cout << encode(a + b);
    }
    else if (t == 2)
    {
        string str;
        cin >> str;

        cout << decode(str);
    }
}