#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

const int SIZE = 7;

int n, slope;
int sequence[SIZE]; //수열
set<int> s; //주어진 수를 중복하지 않고 오름차순으로 저장할 컨테이너


//재귀함수로 구현한 백트래킹
//cnt : 수열의 인덱스 (= 현재 수열의 길이)
void backtracking(int cnt) {

    if (cnt == slope) { //기저조건
        for (int i = 0; i < cnt; i++)
            cout << sequence[i] << ' ';
        cout << '\n';
        return;
    }

    for (int iter : s) {

        sequence[cnt] = iter; //수열 저장

        backtracking(cnt + 1); //호출

    }
}

int main() {
    //입력
    cin >> n >> slope;

    while (n--) {

        int t;
        cin >> t;
        s.insert(t);

    }

    backtracking(0);


    return 0;
}