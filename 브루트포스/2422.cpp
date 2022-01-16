#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* N종류의 아이스크림 중 함께 섞지 않아야하는 아이스크림을 피해 3가지를 선택.
*/

int getTotalCase(int n, vector<vector<int>> ban) {
	int ans = 0; //경우의 수

	//세가지 맛 선택
	for (int i = 1; i <= n; i++) {

		for (int j = i+1; j <= n; j++) {

			if (ban[i][j])
				continue;

			for (int k = j+1; k <= n; k++) {

				if (!ban[j][k] && !ban[i][k]) {
					cout << i << ' ' << j << ' ' << k<<'\n';
					ans++;
				}
						
			}
		}
	}

	return ans;
}
int main() {

	int n, m; //아이스크림 수, 섞어먹으면 안되는 조합 개수
	cin >> n >> m;

	vector<vector<int>> ban(n + 1, vector<int>(n + 1, 0));

	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ban[a][b] = ban[b][a] = true;

	}

	cout << getTotalCase(n, ban);
}