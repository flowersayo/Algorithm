#include <iostream>
#include <vector>
#define SIZE_OF_BOARD 19

using namespace std;

typedef pair<int, int> ci;
vector < vector<int>> board;

//direction => 0: 행 , 1: 열, 2:우하향 3:좌하향

int dx[4] = { 1, 0, 1,-1 };
int dy[4] = { 0, 1, 1,1};

bool isSix(int r, int c, int type,int direction) { //육목을 이루고 있는지 확인.

	// 행 : ( 1,1) 이면 (1,0) , (1.6)확인
	// 열 : (1,1) 이면 (0,1), ( 6,1)확인
	// 우하향 : (1,1) 이면 (0,0) ,(6,6)확인
	// 좌하향 : (2,2) 이면 (1,3),(7,-3) 확인 

	if (r - dy[direction] <= SIZE_OF_BOARD && c - dx[direction] <= SIZE_OF_BOARD) { // 범위 체크
		//cout << "check한 좌표" << r - dy[direction] << "," << c - dx[direction]<<"type:" << type;
		if ( board[r - dy[direction]][c - dx[direction]] == type) {
			
			return true;
		}
	}
	
	if (r + dy[direction] * 5 <= SIZE_OF_BOARD && c + dx[direction] * 5 <= SIZE_OF_BOARD) {// 범위체크
		//cout << "check한 좌표" << r + dy[direction] * 5 << "," << c + dx[direction] * 5<<"type:" << type;
		if (board[r + dy[direction] * 5][c + dx[direction] * 5] == type)
		{
		
			return true;
		}

	}

	return false;

}

// (r,c)에서 type색 돌이 오목을 이루고 있는지 확인 
bool checkRow(int r,int c,int type) { // 행방향

	for (int i = c; i < c+5; i++) {

		if (i > SIZE_OF_BOARD)
			return false;

		if (board[r][i] != type)
			return false;

	}


		return true;
	
}


bool checkCol(int r, int c, int type) { // 열방향

	
	for (int i = r; i < r + 5; i++) {
		if (i > SIZE_OF_BOARD)
			return false;

		if (board[i][c] != type)
			return false;
	
	}


	return true;

}


bool checkRightBelowDgl(int r, int c, int type) { // 우하향 대각선


	int i, j;
	for ( i = r,  j = c; i < r + 5; i++,j++) {
		if (i > SIZE_OF_BOARD || j> SIZE_OF_BOARD )
			return false;

			if (board[i][j] != type)
				return false;
		
	}


	return true;

}


bool checkLeftBelowDgl(int r, int c, int type) {	// 좌하향 대각선


	int i, j;
	for (i = r, j = c; i < r + 5; i++, j--) {

		if (i > SIZE_OF_BOARD || j > SIZE_OF_BOARD ||j<1)
			return false;

		if (board[i][j] != type)
			return false;

	}

	return true;

}
ci getWinner(vector < vector<int>> board) { // 이긴 돌의 좌표 반환. 만일 승부가 결정되지 않은 경우 {-1,-1}반환
	
	ci location = { -1,-1 };//좌표
	bool check[3] = { false,false,false }; //각각의 돌이 이겼는지 여부

	for (int i = 1; i <= SIZE_OF_BOARD; i++) {
		for (int j = 1; j <= SIZE_OF_BOARD; j++) {
			//cout << "(" << i << ',' << j << ")";
			int color = board[i][j]; // 이번턴에 (i,j)에 놓인 돌의 색상

			if (color == 0) //빈곳이라면
				continue;

			if (checkRow(i, j, color)&& !isSix(i, j, color, 0)) {
				check[color] = true;
				//cout << "행오목";
				location = { i,j };
			}
			else if (checkCol(i, j, color) && !isSix(i, j, color, 1)) {
				check[color] = true;
				//cout << "열오목";
				location = { i,j };
			}
			else if (checkRightBelowDgl(i, j, color) && !isSix(i, j, color, 2)){
				check[color] = true;
				//cout << "우하향오목";
				location = { i,j };
			}
			else if (checkLeftBelowDgl(i, j, color) && !isSix(i, j, color, 3)) {
				check[color] = true;
				//cout << "좌하향오목";
				location = { i,j };
			}
			//cout << location.first<<' '<<location.second<<"\n";
			//cout << check[1] << check[2]<<"\n";
				
		}


	}


	if (check[1] ^ check[2]) {
		return location;
	}
	else { //승부가 결정나지 않은 경우
		return { -1,-1 };
	}

}

int main() {
	
	board.assign(SIZE_OF_BOARD+1, vector<int>(SIZE_OF_BOARD+1, -1));

	// 0 : 빈칸 , 1 : 검은색 , 2: 흰색

	for (int i = 1; i <= SIZE_OF_BOARD; i++) {
		for (int j = 1; j <= SIZE_OF_BOARD; j++) {
			cin >> board[i][j];
		}

	}
	
	ci ans = getWinner(board);
	if (ans.first == -1 && ans.second == -1) { 
		cout << 0;
	}
	else {
		cout << board[ans.first][ans.second]<<"\n";
		cout << ans.first << ' ' << ans.second;

	}

}