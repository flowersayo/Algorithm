#include<iostream>

using namespace std;


int main() {

	int x, y, w, h;


	cin >> x >> y >> w >> h;

	int min_h = min(h - y, y); //상하비교
	int min_w = min(w - x, x); //좌우비교

	int min_distance =min(min_h, min_w);

		cout << min_distance;

}