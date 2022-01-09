#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define LIKE_NUM 4 

using namespace std;
typedef pair<int, int> ci; //좌석 좌표

vector<vector<int>> seat;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int max_likes;

vector<vector<ci>> count(int n, vector<int> likes) {

	// dp[i][j].first : 상하좌우로 좋아하는 학생이 몇명있는지 저장.
	// dp[i][j].second : 상하좌우로 인접한 비어있는 공간이 몇개있는지 저장.

	vector<vector<ci>> dp(n + 1, vector <ci>(n + 1, {-1,-1}));

	max_likes = 0; // 좋아하는 학생이 최대로 인접한 횟수의 최댓값. 

	int cnt_like; // 인접한 좋아하는 친구 횟수
	int cnt_vacant; //인접한 비어있는 공간 갯수

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (seat[i][j] != 0) //비어있지 않다면
				continue;

			cnt_like = 0; 
			cnt_vacant = 0; 

			for (int k = 0; k < 4; k++) { //상하좌우 조사

				int adjacent_x = i + dx[k];
				int adjacent_y = j + dy[k];

				if (adjacent_x<1 || adjacent_x>n || adjacent_y<1 || adjacent_y>n) //범위 벗어나면
					continue;

				if (find(likes.begin(),likes.end(),seat[adjacent_x][adjacent_y]) != likes.end()) //인접한 칸이 likes 목록에 존재한다면 
					cnt_like++;

				if (seat[adjacent_x][adjacent_y] == 0) //비어있다면
					cnt_vacant++;
			}
			dp[i][j].first = cnt_like;
			dp[i][j].second = cnt_vacant; 

			max_likes = max(cnt_like, max_likes);
			
			
		}

	}

	return dp;
}

// dp배열 이용해 가능한 후보군 추리기
vector<vector<int>> discernPossible(int n, vector<vector<ci>>& dp) {

	vector<vector<int>> possible; //가능한 후보 좌석
	possible.assign(n + 1, vector <int>(n + 1, false));

	int max_vacant = 0; // max_likes 를 지닌 좌석 후보중에 인접한 비어있는 공간 갯수의 최댓값. 

	// 비어있는 칸 중에서 좋아하는 학생이 가장 많이 인접한 칸들에 true 표시
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (dp[i][j].first != max_likes || seat[i][j] !=0)
				continue;

			possible[i][j] = true; // 조건 1 거르기
			max_vacant = max(max_vacant, dp[i][j].second);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j].first != max_likes)
				continue;

			if(dp[i][j].second != max_vacant)
				possible[i][j] = false; // 조건 2 거르기
		}
	}
	/*
	// 디버깅용 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (possible[i][j])
				cout << 'O'<<' ';
			else
				cout << 'X'<<' ';
		}
		cout << "\n";
	}
	cout << "\n";
	*/

	return possible;
}

// possible 2차 배열을 이용해 학생이 위치할 자리 정하기
ci getSeat(int n, vector<vector<int>> possible) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (possible[i][j])
				return { i,j };
		}
	}

}

int getSatisfaction(int n, vector<vector<int>> likes) {

	int total=0; //만족도 합
	int cnt_like; // 인접한 좋아하는 친구 수

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			cnt_like = 0;
			int std = seat[i][j]; 
			for (int k = 0; k < 4; k++) { //상하좌우 조사

				int adjacent_x = i + dx[k];
				int adjacent_y = j + dy[k];

				if (adjacent_x<1 || adjacent_x>n || adjacent_y<1 || adjacent_y>n) //범위 벗어나면
					continue;

				if (find(likes[std].begin(), likes[std].end(), seat[adjacent_x][adjacent_y]) != likes[std].end()) //인접한 칸이 likes 목록에 존재한다면 
						cnt_like++;
		
			}

			switch (cnt_like) {
			case 0: total += 0;
				break;
			case 1: total += 1;
				break;
			case 2: total += 10;
				break;
			case 3: total += 100;
				break;
			case 4: total += 1000;
				break;

			}
		}
	}
	return total;

}



int main() {

	int n;

	cin >> n;

	 seat.assign(n + 1, vector <int>(n + 1, 0)); // 0 : 학생 존재 X
	 vector <vector<int>> likes(n * n + 1, vector <int>(4, 0)); // likes[i] : 번호 i인 학생이 좋아하는 학생목록

	int std; 
	
	int t = n * n;
	while(t--) {
	
		cin >> std;
		for (int i = 0; i < LIKE_NUM; i++) {
			cin >> likes[std][i];
		}

		//연산 
		vector<vector<ci>> dp = count(n, likes[std]);
		vector<vector<int>> possible = discernPossible(n,dp);

		ci selected = getSeat(n, possible);

		seat[selected.first][selected.second] = std;

		/*
		 // 디버깅용 출력
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << seat[i][j] << ' ';
			}
			cout << "\n";
		}
		cout << "\n";
		*/
		
		

		
		
	}

	cout << getSatisfaction(n,likes);

}