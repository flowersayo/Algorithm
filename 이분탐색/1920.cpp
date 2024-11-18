#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int n, m, target;

    cin >> n;

    vector<int> A(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> target;

        cout << binary_search(A.begin(), A.end(), target) << "\n";
    }
}