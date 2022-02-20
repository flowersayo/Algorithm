#include <iostream>


using namespace std;

long long getSize(int n) { //크기가 n일때의 지구의 칸수


	long long size;

	//등차수열의 합 공식
	size = n * ( 2 * 4 + ((long long)n - 1) * 4 ) / 2;

	return size;
}


int main() {

	int t;
	int n, k;

	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (n - k-1 < 1) {
			cout << getSize(n) << "\n";
		}

		else
		cout << getSize(n) - getSize(n - k - 1)<<"\n";
	}

	
}