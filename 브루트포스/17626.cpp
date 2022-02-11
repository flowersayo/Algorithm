#include <iostream>
#include <vector>
#include <math.h>
#define INF 123456789

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> dp(n + 1, INF);
	

	//dp초기화 
	for (int i = 1; i <= sqrt(n); i++)
		dp[i * i] = 1;

	for (int i = 2; i <=n; i++) {

		for (int j = 1; j <= sqrt(i);j++) { //i보다 작은 제곱수 구하기

			int temp = 1 + dp[i - j * j];
			dp[i] = min(temp, dp[i]);

		}
	}

	cout << dp[n];
}