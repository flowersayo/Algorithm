#include <iostream>
#define THE_HOUR_OF_DAY 24

using namespace std;

int fatigue; //피로도
int throughput; //처리양
void work(int A,int B,int C,int M) {

	if ((fatigue + A) > M) {
		//휴식 취하기
		fatigue -= C;
		if (fatigue < 0)
			fatigue = 0;
	}
	else {
		fatigue += A;
		throughput += B;
	}
}


int main() {

	fatigue = 0;
	throughput = 0;

	int A, B, C, M; // 피로도증가량,일처리,피로도감소량,역치
	cin >> A >> B >> C >> M;
	int t = THE_HOUR_OF_DAY;

	while (t--) {

		work(A, B, C, M);

	}

	cout << throughput;
}
