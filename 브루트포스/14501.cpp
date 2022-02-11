#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

int max_profit=-1; //최대수익

void consult(int n,int profit,int day, vector<ci> consulting) { //총 일수, 수익,현재 날짜, 상담 정보


	if (day > n) //n일차를 넘어서면
	{
		max_profit = max(max_profit, profit); // 최대 수익 갱신.
		return;
	}


	if (day + consulting[day].first <= n+1) { // 회의를 해도 일자를 초과하지 않으면

		//day날 회의를 하고 회의를 마친날로 넘어감.
		consult(n, profit + consulting[day].second, day + consulting[day].first, consulting);
	}
	//day날 회의를 하지 않고 다음날로 넘어감.
	consult(n, profit, day + 1, consulting);

	

}

int main() {

	int n;

	cin >> n;

	vector<ci> consulting(n+1, { 0,0 }); // first : 시간 , second : 금액(보수)

	for (int i = 1; i <= n; i++) {
		cin >> consulting[i].first >> consulting[i].second;
	}

	consult(n, 0, 1, consulting);
	cout << max_profit;

}