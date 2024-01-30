#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> interest(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> interest[i];
    }

    int total = 0;
    int non_registed_sum = 0;
    bool isRegistered;
    for (int i = 0; i < n; i++)
    {
        cin >> isRegistered;
        total += interest[i];
        if (!isRegistered)
        {
            non_registed_sum += interest[i];
        }
    }

    cout << total << "\n"
         << non_registed_sum;
}
