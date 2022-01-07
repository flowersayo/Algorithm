#include <iostream>
#include <string>

using namespace std;

int main() {

	string str;

	getline(cin,str);
	//getline(cin,str,'\n')l

	int cnt = 0; // 공백문자가 등장한 횟수

	for (int i = 0; i < str.length(); i++) {
		//cout << str[i] << ' ';
		if (str[i] == ' ') {
			
			cnt++;
		}
	}

	if (str[0] == ' ')
		cnt--;
	if (str[str.length() - 1] == ' ')
		cnt--;

	cout << cnt + 1;

}