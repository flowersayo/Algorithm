#include <iostream>
#include <math.h>

using namespace std;

const long long MOD = 1000000007;

long long multiply(long long x, long long n)
{ // x^n를 구하는 함수

    if (n == 1)
    {
        return x;
    }

    long long half = multiply(x, n / 2);
    long long result = (half * half) % MOD; // half * half 에서 overflow 가 발생할 수 있으므로 MOD 로 나눠주어야함

    if (n % 2 == 0)
    {
        return result;
    }
    else
    {
        return (x * result) % MOD;
    }
}

int main()
{

    long long k, p, n;

    cin >> k >> p >> n;

    long long times = n * 10; // 번식 횟수

    cout << (k * multiply(p, times)) % MOD;
}