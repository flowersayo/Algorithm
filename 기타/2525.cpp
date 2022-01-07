#include<iostream>

using namespace std;


int main() {

	int h, m,t;

	cin >> h >> m;
	cin >> t;

	int sum = (m + t);

		h += sum / 60;
		m = sum % 60;

			if (h >= 24)
			h = h - 24;

	

	cout << h << ' ' << m;
}