#include <iostream>
#include <vector>
#include <string>

using namespace std;\
/**
* 정수 N과 K가 입력되었을 때 00시 00분 00초부터 N시 59분 59초까지의 모든 시각 중에서 
* K가 하나라도 포함되는 모든 시각을 세는 프로그램
*/
//일반숫자에는 0이 붙지 않으므로 formatting 해주어야함.

string padStart(string str, int max_length, const char& c) {

	if (str.length() > max_length) {
		return str.substr(0, max_length);
	}
	else if (str.length() == max_length) {
		return str;
	}
	else {
		string result = str;

		while (result.length() != max_length) {
			result = c + result; // 앞자리에 추가하기
		}
		return result;
	}

}
int count(int n,int target) {
	
	int cnt = 0;
	char target_c = target+'0';
	for (int i = 0; i <= n; i++) {
	
		if (padStart(to_string(i),2,'0').find(target_c) != string::npos) { //3이 포함되어있다면 
			cnt += 60 * 60 ;
			continue;
		}

		for (int j = 0; j < 60; j++) {

			if (padStart(to_string(j), 2, '0').find(target_c) != string::npos) {
				cnt+=60;
				continue;
			}

			for (int k = 0; k < 60; k++) {

				if (padStart(to_string(k), 2, '0').find(target_c) != string::npos) {
					cnt++;
				}
			}

		}

	}
	return cnt;
}

int main() {

	int n, k;
	cin >> n >> k;
	
	cout<< count(n, k);
}