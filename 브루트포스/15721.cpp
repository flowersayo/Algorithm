#include <iostream>
#include <vector>

using namespace std;

/**
* 뻔 – 데기 – 뻔 – 데기 – 뻔(x n번) – 데기(x n번)
*/

int getNum(int n,int t,string target, vector<string> &sentence) {


	int std = 0; // 시작학생 번호
	int cnt = 0; 
	int di = 3; // 뻔 - 데기 추가 간격

	
	while (true) {

		for (int i = 0; i < sentence.size(); i++) {
			if (sentence[i] == target) {
				
				cnt++;
				if (cnt == t) //t번째 도달시 종료.
					return std;
			}
			std++;
			if (std == n)
				std %= n;
		}
		sentence.insert(sentence.begin() + 4, "뻔");
		sentence.insert(sentence.begin() + 4 + di, "데기");
		di++;
	}


}

int main() {

	int n, t, w; //총인원수. t번째 w(뻔 or 데기) 

	string word[] = { "뻔","데기" };
	vector<string> sentence{ "뻔", "데기", "뻔", "데기", "뻔", "뻔", "데기", "데기" };

	cin >> n >> t >> w;  

	cout<<getNum(n, t, word[w],sentence);
}