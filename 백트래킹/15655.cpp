#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, slope;
int pArr[8] = { 0, };
int num[8] = { 0, };

void permutaion(int depth) {

	if (depth == slope) {
		for (int i = 0; i < slope; i++) {
			cout << pArr[i] << ' ';
		}
		cout << '\n';
		return;
	}


	for (int i = 0; i < n; i++) {

		pArr[depth] = num[i];
		permutaion(depth + 1);

	}
}

int main() {

	cin >> n >> slope;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);
	permutaion(0);
}