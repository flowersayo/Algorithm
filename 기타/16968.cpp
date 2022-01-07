#include<iostream>

#define ALPABET 26
#define NUM 10

using namespace std;

int main() {

	string str; //차량 번호판 형식
	
	
	cin >> str;

	int ans = 1; //경우의 수 

	if (str[0] == 'd') 
		ans *= NUM;
	else
		ans *= ALPABET;

	for (int i = 1; i < str.length(); i++) {

		if (str[i] == 'd') {
			if (str[i - 1] == 'd') // d d 
				ans *= (NUM-1);
		
			else 	// c d
				ans *= NUM;
			
		}

		else { 
			if (str[i - 1] == 'c') // c c
				ans *= (ALPABET- 1);
			
			else 	// d c
				ans *= ALPABET;
			

		}
	}

	cout << ans;
}