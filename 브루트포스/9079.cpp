#include <iostream>
#include <vector>

using namespace std;
#define SIZE_OF_BOARD 3

void reverseRow(vector<vector<char>>& board, int r, int c) { // 행 을 뒤집는 함수

	for (int i = 0; i < SIZE_OF_BOARD; i++) {
		for (int j = 0; j < SIZE_OF_BOARD; j++) {

		}
	}
}
void reverseCol(vector<vector<int>>& board, int r, int c) { // 열을 뒤집는 함수


}

void reverseDiagonal(vector<vector<char>>& board, int r, int c) { // 대각선을 뒤집는 함수

}

bool check(vector<vector<char>>& board) { // 모두 같은면 (H or T) 을 보이고 있는지 확인.

	char mark = board[0][0];

	for (int i = 0; i < SIZE_OF_BOARD; i++) {
		for (int j = 0; j < SIZE_OF_BOARD; j++) {
			if (board[i][j] != mark)
				return false;
		}
	}

	return true;
}

int getMinCalc(vector<vector<char>> board) {

	for (int i = 0; i < SIZE_OF_BOARD; i++) {
		for (int j = 0; j < SIZE_OF_BOARD; j++) {
			
		}
	}


}
int main() {

	int test_case;

	vector<vector<char>> board(SIZE_OF_BOARD, vector<char>(SIZE_OF_BOARD, 0));
	cin >> test_case;

	while (test_case--) {
		for (int i = 0; i < SIZE_OF_BOARD; i++) {
			for (int j = 0; j < SIZE_OF_BOARD; j++) {
				cin >> board[i][j];
			}
		}



	}
	
}