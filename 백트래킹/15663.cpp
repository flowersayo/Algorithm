#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, slope;
int check[9] = { false, };
int pArr[8] = { 0, };
int num[8] = { 0, };
bool repeated[9] = { false, }; 

void permutaion(int depth) {

	if (depth == slope) {
		for (int i = 0; i < slope; i++) {
			cout << pArr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 같은 숫자가 중복되서 사용되지 않도록! 

	int before = -1;
	for (int i = 0; i < n; i++) {
		if (!check[i] && before!=num[i]) {
			check[i] = true;
			before = num[i];
			pArr[depth] = num[i];
			permutaion(depth + 1);
			check[i] = false;
		}
	}
}
int main() {
	cin >> n >> slope;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);

	permutaion(0);
}