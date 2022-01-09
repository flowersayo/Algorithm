#include <iostream>
#include <stack>
#include <map>

using namespace std;

map <char, char> blanket; // 괄호 짝 저장

bool isVPS(string str) {

	stack<int> s;


	for (int i = 0; i < str.length(); i++) {

		switch (str[i]) {
			
		case '(':
			s.push(str[i]);
			break;

		case ')':
			if (!s.empty()&& s.top() == blanket[str[i]])
				s.pop();
			else
				return false;

		}
	}

	return s.empty(); 
	
}

int main() {


	int n;
	string str;
	blanket[')'] = '(';

	cin >> n;


	while (n--) {

		cin >> str;

		if (isVPS(str))
			cout << "YES\n";
		else
			cout << "NO\n";

	}


}