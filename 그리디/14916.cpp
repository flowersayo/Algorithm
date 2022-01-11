#include <iostream>
#include <vector>
# define INF 123456789

using namespace std;

//dp 풀이
int coinCnt(int change) { // 최소 동전의 개수

	vector<int> dp(change + 1, INF);

	dp[2] = 1;
	dp[4] = 2;
	dp[5] = 1;

	if(change<=5)
		return dp[change] == INF ? -1 : dp[change];

	int cnt = 0;
	for (int i = 6; i <= change; i++) {
		dp[i] = min(dp[i - 2], dp[i - 5])+1; 
	}

	/*for (int i = 1; i < dp.size(); i++)
		cout << i<<':'<< dp[i] << ' ';*/
		

	// change>5이면 2원, 5원만으로 거슬러주기 가능.
	return dp[change];
}

//그리디 풀이
// 5원짜리를 쓸 수 있는만큼 쓰고 남은 나머지가 2의 배수이면 2로 나누기
// 아니라면 5원짜리 하나를 빼서 짝수를 만든 후 2원짜리로 조합할 수 있게끔 하기.

int coinCnt2(int n) {
	int cnt = 0;
	int div5 = n / 5, mod5 = n % 5;

	if (mod5 % 2 == 1){
		div5--; //5원짜리 하나빼기
		mod5 = mod5 + 5;
	}

	if (div5 < 0) cnt = -1;
		else cnt = div5 + mod5 / 2;

		return cnt;
}

int main() {

	int n;
	cin >> n;

	//cout << coinCnt(n);
	cout << coinCnt2(n);


}