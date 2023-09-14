#include <string>
#include <vector>
#include <iostream>

using namespace std;

 vector<int> answer; // 임티플 가입자 수, 매출액

vector<int> sale; // 이모티콘 할인률 저장
void dfs(int idx, vector<vector<int>> users, vector<int> emoticons){
    
    if(idx == emoticons.size()){ // 모든 이모티콘의 할인률 책정이 완료되면
        
        int sales = 0;
        int emoticon_plus_member = 0; 
        
        // 각 유저의 매출액 계산해서 임티플 가입자수랑 매출액 총액을 계산
        for(int i=0;i<users.size();i++){
            
            int sale_to_buy = users[i][0]; // 비율 % 이상의 할인이 있는 이모티콘을 모두 구매
            int thresholds = users[i][1]; // 가격 역치
            
            int total = 0;
            for(int j=0;j<idx;j++){
                
                if(sale[j]>=sale_to_buy){ // 할인률이 더 높으면
                    
                    total += (emoticons[j] / 100 * (100 - sale[j]));
                    
                }
            }
            
            if(total>=thresholds){
                emoticon_plus_member++;
            }
            else{
                sales += total;
            }
            
         
           
            
            
        }

        if(answer[0] < emoticon_plus_member ){ // 가입자 수 최댓값 업데이트
            
                answer[0] = emoticon_plus_member; 
                  answer[1] = sales;
               
        }
        else if (answer[0] == emoticon_plus_member && answer[1] < sales){
            answer[1] = sales;
        }
        return;
    }
    
    
    // 각 이모티콘 할인률
    
	for(int i=10;i<=40;i+=10){
        
        sale[idx]=i;
        dfs(idx+1, users,emoticons);
        
    }
    
    
    
}
/**
[이모티콘 할인행사]
https://school.programmers.co.kr/learn/courses/30/lessons/150368

=> dfs 브루트포스로 4^7 개에 해당하는 모든 할인률 조합 경우의 수 시도해보기!

*/
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
   
    sale.assign(emoticons.size(),0);
    
    answer.assign(2,-1);
    
    dfs(0,users,emoticons);
    
    return answer;
}