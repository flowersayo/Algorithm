#include <iostream>

using namespace std;

int main(int argc, char **argv)
{

    int n;
    cin >> n;

    int x = 2; // 한변의 길이

    for (int i = 0; i < n; i++)
    {

        x = x + (x - 1);
    }

    cout << x * x;
}