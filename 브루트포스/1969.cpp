#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
 Hamming Distance란 길이가 같은 두 DNA가 있을 때, 각 위치의 뉴클오티드 문자가 다른 것의 개수
 ->	각 dna의 i번째 인덱스에서 가장 많이 등장한 뉴클레오타이드를 선택,
*/


// map에서 가장 많이 등장한 뉴클레오 타이드 반환
char getMostFrequency(map <char, int> frequency) { 

	int max= -1;
	char c;
	for (auto iter : frequency) {
		if (max < iter.second) {
			max = iter.second;
			c = iter.first;
		}
	}

	return c;
}

// cmp와 dna 각각을 비교하여 Hamming Distance의 합을 구하는 함수
int getSumOfHD(vector<string> dna,string cmp) {

	int sum = 0;

	for (int i = 0; i < cmp.length(); i++) {

		for (int j = 0; j < dna.size(); j++) {

			if (dna[j][i] != cmp[i])
				sum++;
		}
	
	}
	return sum;
}

pair<string,int> getMinHD(vector<string> dna,int n, int m) {

	pair<string, int> ans = { "",0 };
	

	for (int i = 0; i < m; i++) {
		map <char, int> frequency = { {'A',0},{'C',0} ,{'G',0} ,{'T',0} };

		for (int j = 0; j < n; j++) {

			frequency[dna[j][i]]++;
			
		}
		ans.first += getMostFrequency(frequency);
		
	}

	ans.second = getSumOfHD(dna, ans.first);
	return ans;
}

int main() {

	int n, m; 
	cin >> n >> m;
	vector<string> dna(n, "");

	for (int i = 0; i < n; i++) {
		cin >> dna[i];
	}

	pair<string, int> ans = getMinHD(dna, n, m);
	cout << ans.first << '\n' << ans.second;

}