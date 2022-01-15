#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

ci solve(int a,int b,int c,int d,int e,int f) {

	for (int i = -999; i <= 999; i++) {
		for (int j = -999; j <= 999; j++) {

			if (a * i + b * j == c && d * i + e * j == f)
				return { i,j };	
		}

	}

}

int main() {

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	ci ans = solve(a,b,c,d,e,f);
	cout << ans.first << ' ' << ans.second;
}