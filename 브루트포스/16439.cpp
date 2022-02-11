#include <iostream>
#include <vector>

using namespace std;

//뽑힌 치킨 바탕으로 score계산하기
int getScore(int c1,int c2,int c3, vector<vector<int>> satisfaction,int n,int m) {

	int score=0;
	for (int i = 0; i < n; i++) {
		int max; //satisfaction[n][c1] satisfaction[n][c2] satisfaction[n][c3] 중 가장 큰 값

			if (satisfaction[i][c1] <= satisfaction[i][c2]) {
				max = satisfaction[i][c2];
			}
			else {
				max = satisfaction[i][c1];
			}

			if (satisfaction[i][c3] >= max)
				max = satisfaction[i][c3];

			score += max;
	}
	return score;
}
int pickChicken(int n,int m,vector<vector<int>> satisfaction) {

	int max_score = -1;
	//3가지 치킨 뽑기
	for (int i = 0; i < m; i++) {
		for (int j = i+1; j < m; j++) {
			for (int k = j+1; k < m; k++) {
				max_score = max(max_score, getScore(i, j, k, satisfaction, n, m));
			}
		}
	}

	return max_score;
}

int main() {

	int n, m; // 회원수,치킨 종류

	cin >> n >> m;

	vector<vector<int>> satisfaction(n, vector<int>(m, 0)); // 회원들의 치킨 선호도
	//satisfaction[i][j] 는 i번 회원의 j번째 치킨에 대한 만족도

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> satisfaction[i][j];
	
		}

	}

	cout << pickChicken(n, m, satisfaction);

}