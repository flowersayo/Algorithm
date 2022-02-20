#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef pair<int, int> ci;



bool cmp(ci c1, ci c2) { //인원수 기준 정렬
	
	return c1.first < c2.first; // 오름차순 . 

}

int match(vector<ci> request, vector<ci> bus) {

	multiset<int> ms;
	int p1 = 0,p2=0; // 버스, 배차요청 가리키는 투포인터
	int ans=0;
	while (p1 < bus.size() ) {

		//cout << "p1: "<< p1<<"\n";
		ci currentBus = bus[p1];

		int n = currentBus.first; //정원
		int arriving_time = currentBus.second; //도착시간

		//시간기준으로 배차 요청 추가하기
		while(p2 < request.size())
		{
			if (n >= request[p2].first) { //인원수 조건 확인
				ms.insert(request[p2].second);
				p2++;
			}
			else
				break;
		}

		// 넣어준 배차요청들에 한해서 시간 조건 만족하는 첫번째 배차요청 match
		auto iter = ms.lower_bound(arriving_time);


		if (iter != ms.end()) { //만족시킬 수 있는 배차요청이 존재한다면.
			ms.erase(iter);
			ans++;
		}

		// 다음 배차 요청 처리 
		p1++;


	}

	return ans;
}


int main() {

	int n, m;

	cin >> n >> m;

	vector<ci> request(n, { 0,0 }); //탑승인원, 최대 대기시간
	vector<ci> bus(m, { 0,0 }); // 정원 , 도착예정시간

	// 버스 정원 > 탑승인원. 도착예정시간 <= 최대 대기시간

	// a b 의 배차요청은
	// a 이상 b 이내인 버스 가능
	for (int i = 0; i < n; i++) {
		cin >> request[i].first >> request[i].second;
	}

	for (int i = 0; i < m; i++) {
		cin >> bus[i].first >> bus[i].second;
	}

	sort(request.begin(), request.end(),cmp);
	sort(bus.begin(), bus.end(), cmp);
	cout << match(request, bus);
}