#include <iostream>
#include <vector>

using namespace std;
/**
* 블랙잭 : 카드의 합이 21을 넘지 않는 한도 내에서, 카드의 합을 최대한 크게 만들기
*/

//n장 중에서 3장 뽑기 
int getApproximation(int n,int target,vector<int> cards) {

	int sum,ans =0 ; 
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {

			for (int k = j+1; k < n; k++) {

				sum = cards[i] + cards[j] + cards[k];
				if ((sum <= target) && (ans < sum))
					ans = sum;
			}

		}

	}
	return ans;
	
}

int main() {

	int n, m;
	cin >> n >> m;
	vector<int> cards(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}
	cout <<getApproximation(n, m, cards);
}