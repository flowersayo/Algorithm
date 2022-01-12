#include <iostream>
#include <regex>

using namespace std;

 // 정규식에 지정한 문자열과 일치하는 모든 문자열을 치환
 // regex_replace.(대상 문자열, regex(정규식), 치환 문자열)

int main() {

	string str;
	cin >> str;

	 str = regex_replace(str, regex("(XXXX){1}"), "AAAA");
	// cout << str<<"\n";
	 str = regex_replace(str, regex("(XX){1}"), "BB");
	// cout << str << "\n";

	 if (str.find('X')==string::npos) // X가 없다면 = 모든 X가 대체되었다면 
		 cout << str; 
	 else
		 cout << -1;
}