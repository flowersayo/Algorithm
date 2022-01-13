#include<iostream>
#include<vector>

using namespace std;

// i 번째 전구의 상태를 x로 변경
void changeState(vector<int> &state,int i,int x) {
	state[i] = x;
}

//l번째부터r번째까지의 전구의 상태를 변경한다. (켜져있는 전구는 끄고, 꺼져있는 전구는 킨다.
void toggleState(vector<int>& state, int l, int r) {

	for (int i = l; i <=r; i++)
		state[i] = !state[i]; //상태토글
}

// l번째부터 r번째까지의 전구를 끈다
void turnOffAll(vector<int>& state, int l, int r) {

	for (int i = l; i <= r; i++)
		state[i] = 0;
}

//l번째부터 r번째까지의 전구를 킨다.
void turnOnAll(vector<int>& state, int l, int r) {
	for (int i = l; i <=r ; i++)
		state[i] = 1;
}


int main() {

	int n, m, a, b, c;
	cin >> n >> m;

	vector<int> state(n + 1, 0);

	//입력
	for (int i = 1; i <= n; i++)
		cin >> state[i];

	//연산
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		
		switch (a) {
		case 1: changeState(state, b, c);
			break;
		case 2:toggleState(state, b, c);
			break;
		case 3:turnOffAll(state, b, c);
			break;
		case 4:turnOnAll(state, b, c);
			break;
		}

	}

	//출력
	for (int i = 1; i < state.size(); i++)
		cout << state[i]<<' ';


}