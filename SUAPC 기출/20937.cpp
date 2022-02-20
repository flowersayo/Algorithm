#include <iostream>
#include <map>

using namespace std;



int numOfMaxDish(map<int, int> dish) {

	int ans = -1;
	for (auto iter : dish) {

		ans = max(ans, iter.second);
	}

	return ans;
}
int main() {

	int n;
	cin >> n;
	map<int, int> dish; //떡국그릇의 개수

	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		dish[k]++;
	}


	cout << numOfMaxDish(dish);
}