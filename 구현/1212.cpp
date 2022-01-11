#include <iostream>
#include <string>

using namespace std;

void octalToBinary(string octal) {

	string binary = "";
	string octals[8] = { "000","001","010","011","100","101","110","111"};

	int n;
	for (int i = 0; i < octal.length(); i++) {
		n = octal[i] - '0';
		binary+=octals[n];
	}

	// 다듬기
	n = octal[0] - '0';
	if (n == 0 || n == 1) {
		binary.erase(0, 2); //00 제거
	}
	else if (n == 2 || n == 3) {
		binary.erase(0, 1); // 0 제거
	}

	cout << binary;

}


int main() {

	string octal;
	cin >> octal;
	
	 octalToBinary(octal);
}