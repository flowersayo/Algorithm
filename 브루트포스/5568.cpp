#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int cnt = 0; // 총 경우의 수 

set<int> cases; // 만들어진 숫자 저장.

bool check(vector <int> &cards,int k) {

    string n ="";
    for (int i = 0; i < k; i++) {
        n += to_string(cards[i]);
    }
    
    //cout << n<<'\n';

    if (cases.find(stoi(n)) == cases.end()) { // 존재하지 않는 숫자였다면
        cases.insert(stoi(n));
        return true;
    }


        return false;
}
void permutation(vector <int> cards, int depth, int n, int k)
{ 
    if (depth == k)
    {
        if (check(cards, k)) { //유효한 카드인지 확인
            cnt++;
       }
       
        
        return;
    }
    
    for(int i = depth; i < n; i++) // depth가 증가할수록 prefix증가. 
    {
        swap(cards[depth], cards[i]);   // depth 번째 원소 스왑 
        permutation(cards, depth + 1, n, k);  // 재귀
        swap(cards[depth], cards[i]);  // 다시 원래 위치로 되돌리기
    }
}


int main() {

	int n, k;

	cin >> n >> k;

	vector <int> cards(n, 0);
	for (int i = 0; i < cards.size(); i++) {
		cin >> cards[i];
	}

    permutation(cards, 0, n, k);

    cout << cnt;
}