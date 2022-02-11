#include <iostream>
#include <vector>
#include <set>
#define SIZE_OF_BOARD 19
#define INF 123456789
using namespace std;



int min_cost; //최소비용

typedef struct {
	int price;
	string name;
}Book;

void makeWord(int total,string target,vector<Book> &booklist,int strIdx, set<int> buy) { //타겟 스트링,북리스트,타겟스트링의 몇번째 단어인지, 지금껏 산 책 목록

	cout << total<<" "<<strIdx<<"\n";

	if (strIdx == target.length())
	{
		min_cost = min(min_cost, total); //최소비용 갱신

		cout << "최종" <<total << " " << strIdx << "\n";
	}

	for (int i = 0; i < booklist.size(); i++) {
		string name = booklist[i].name;
		int idx = name.find(target[strIdx]); // 현재 차례의 단어를 찾은 곳의 위치

		if (idx !=-1) { // 단어를 찾았다면
			int weight= booklist[i].price;// 가격 가중치
			char keep = booklist[i].name[idx];
			booklist[i].name[idx] = ' '; // 단어 중복사용 방지
		
			
			cout << "\n";

			bool check =false; //원래 있었던 책인지.
			if (buy.find(i) != buy.end()) {
				//현재 구매하려는 책이 이미 구매한 목록에 존재하면
				weight = 0; //추가비용 들지 않음. 
				check = true;
			}
				
			buy.insert(i);  //이문장이 다음번 탐색시에 영향을 줌. 
			cout << strIdx<<"번째 단어를 찾은 책:" << i<<"\n";

		
			makeWord(total + weight, target, booklist, strIdx + 1,buy);
			booklist[i].name[idx] = keep;
			if(!check)//원래 없던 책이라면
			buy.erase(i); //리스트에서 삭제
		}
			

		
	}

}


int main() {

	string target;
	int n;

	cin >> target;
	cin >> n;

	vector<Book> booklist;
	set<int> buy;

	for (int i = 0; i < n; i++) {
		Book book;
		cin>>book.price>>book.name;
		booklist.push_back(book);
	}
	min_cost = INF;
	makeWord(0,target, booklist,0,buy);
	cout << (min_cost==INF?-1:min_cost);
}