#include <iostream>
#include <queue>


using namespace std;

/*
N명의 사람이 원을 이루어 앉음. 
순서대로 K번째 사람을 제거
큐를 이용해서 앞에 있는 사람을 맨뒤로 보낸다.
이때 몇번째사람인지 카운트하여 k번째라면 pop한다. 
*/



int main() {

	int n, k;

	cin >> n >> k;

	queue <int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}


	cout << '<';
	int cnt = 0; //k번째인지 기억.
	int visited = 0; // 방문한 노드 개수

	while (!q.empty()) {

		cnt++;

		if (cnt % k == 0) {
			int node = q.front();
			visited++;

			if (visited != n) {
				cout << node << ", ";
			}
			else {
				cout << node ;
			}

			q.pop();
			cnt = 0;
			
		}
		else {
			int node = q.front();
			q.pop();
			q.push(node);
			
		}
	}
	cout << '>';

}
	





