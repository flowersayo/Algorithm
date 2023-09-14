#include <string>
#include <vector>
#include <map>

using namespace std;

/**
[할인행사]
https://school.programmers.co.kr/learn/courses/30/lessons/131127

슬라이딩 윈도우 활용! 초기 윈도우 사이즈를 고정하고
일정한 범위를 이동하면서 필요 조건을 만족하는 경우 카운트하기

*/


bool canMeet(map<string,int> m,vector<string> want, vector<int> number){
    
     for(int i=0;i<want.size();i++){
            if(m[want[i]]<number[i]){ //수량이 모자란게 있다면 
               return false;
            }
        }
    
    return true;
        
}
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
   
    map<string,int> m; // 재료 개수 저장
    
    for(int i=0;i<10;i++){ 
        m[discount[i]]++;
        
        if(canMeet(m,want,number)){
            answer++;
        }
    }
     // 슬라이딩 윈도우 
    for(int i=0;i<discount.size()-10;i++){
        
        m[discount[i]]--;
        m[discount[10+i]]++;

        if(canMeet(m,want,number)){
            answer++;
        }
    }
    
    return answer;
}