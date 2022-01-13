#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

// 같은 번호의 소가 위치를 바꾼 것이 몇 번인지 세면 된다.
int observe(int cow[],int n,int location) {

	if (cow[n] == -1) { // 처음 등장
		cow[n] = location;
		return 0;
	}

	if( cow[n] != location) { //기존 위치와 다르다면
		cow[n] = location;
		cout << "*";
		return 1;
	}

	return 0; //기존위치와 같다면
	

}
int main() {

	int t,n,location; 
	int cow[11];
	memset(cow, -1, sizeof(cow));
	int cnt = 0; //소가 길을 건너간 최소 횟수

	cin >>t;

	while (t--) {
		cin >> n >> location;
		cnt+=observe(cow, n, location);
	}
	
	cout << cnt;
	
}