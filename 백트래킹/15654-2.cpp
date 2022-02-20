
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n, slope;
	cin >> n >> slope;

	vector<int> pArr(n, 0);

	for (int i = 0; i < n; i++)
		cin >> pArr[i];
	
	sort(pArr.begin(), pArr.end());

		do
		{
			for (int i = 0; i < slope; i++)
				cout << pArr[i] << " ";
			cout << '\n';

			reverse(pArr.begin() + slope, pArr.end());

		} while (next_permutation(pArr.begin(), pArr.end()));

}