#include<iostream>

using namespace std;

int main() {


	string str; //암호

	cin >> str;

	int sum = 0;
	int w = 1;
	int idx = -1;
	int ans = 0;

	string temp = str;


	// * 위치 파악
	for (int j = 0; j < 13; j++) {
		if (str[j] == '*')
			idx =j;

	}

	for (int i = 0; i <= 9; i++) {
		sum = 0;
		w = 1;

		//치환 : 0~9
		
		str[idx] = '0'+i;

		
		//각자릿수 가중치합 계산
		for (int i = 0; i < 12; i++) {
			sum += (str[i]-'0') * w;

			if (w == 1)
				w = 3;
			else
				w = 1;
			//cout << sum << ' ' ;

		}

		//cout << sum<<"\n";
		
	

		if (str[12]-'0' == ( 10 - (sum % 10))|| (str[12] == '0' && sum % 10 == 0)) {
			ans = i;
			break;
		}


	}

	cout << ans;
	


}