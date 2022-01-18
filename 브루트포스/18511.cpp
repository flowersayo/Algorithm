#include <iostream>
#include <vector>
#include <string>

/*n보다 작은 수이므로 n보다 자릿수가 적어도 상관 없음! */
using namespace std;
  
int ans = -1;

//k개의 원소중에 중복을 허용하여 n의 length개를 뽑음. 
//중복 순열

int renew(vector<int> perm,int n,int depth) { //만들어진 수가 조건을 만족하는지 확인하고 갱신할 값 리턴

    if (depth == 0) return ans;

    string temp = "";
    for (int i = 0; i < depth; i++) {
        temp += to_string(perm[i]);

    }

    int maked = stoi(temp);
    if (maked <= n && maked>ans) { // n보다 작거나 같은 수중에서 기존 최댓값보다 크다면
        return maked;
    }
          
    return ans;
        
}

//perm : 수열 저장
void makeLargeNum(vector<int> elements, vector<int> perm,int depth,int n) {

    ans = renew(perm, n,depth);
    if (depth == perm.size())
        return;
    

    for (int i = 0; i < elements.size(); i++)
    {
        perm[depth] = elements[i];
        makeLargeNum(elements, perm, depth + 1,n);
    }
}

int main() {

	int n, k;
    cin>>n>>k;
	vector<int> elements(k, 0);

		for (int i = 0; i < k; i++)
			cin >> elements[i];

        //정수 n이 몇자리 수인지 
        int length = to_string(n).length();
        vector<int> perm(length, 0);
        makeLargeNum(elements, perm, 0, n);

        cout << ans;
}