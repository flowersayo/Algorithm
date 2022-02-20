#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int getMaxLength(vector<int> seq) {

	int max_length = -1;
	if (seq.size() <= 2)
		return seq.size();

	for (int i = 0; i < seq.size()-2; i++) {
		int j = i + 1;
		for (int k = seq.size()-1; k >=i+2; k--) {

			
			if (seq[i] + seq[j] > seq[k]) {
				max_length = max(max_length, k - i + 1);
				
				break;
			}
			
			
		}
	}

	if (seq.size() == 3 && max_length == -1)
		return 2;

	return max_length;


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> seq(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> seq[i];

	}
	sort(seq.begin(), seq.end());

	cout << getMaxLength(seq);
}