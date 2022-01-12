#include <iostream>
#include <vector>

using namespace std;


bool check4(string str,int i) {

	for (int j = 0; j < 4; j++) {
		if (str[i + j] == '.' || (i + j) >= str.size())
			return false;

	}

	return true;
}

bool check2(string str, int i) {

	for (int j = 0; j < 2; j++) {
		if (str[i + j] == '.' || (i+j)>=str.size())
			return false;

	}

	return true;
}

string fill(string str, string polyominos[]) {

	string board="";

	int i = 0;
	while (i < str.length()) {

		//cout << i;
		//cout << board << "\n";
		if (str[i] == '.') {
			board.append(".");
			i++;
			continue;
		}

		if (check4(str,i)) { // 4자리 공간이 있으면
			board.append(polyominos[0]);
			i += 4;
		}
		else if (check2(str,i)) { // 2자리 공간이 있으면
			board.append(polyominos[1]);
			i += 2;
		}
		else
			return "-1";

	}

	return board;

}

int main() {

	string str;
	string polyominos[2] = { "AAAA","BB" };

	cin >> str;

	cout << fill(str, polyominos);

}