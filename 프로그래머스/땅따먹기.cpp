#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    
    int answer=0;
    int row_size = land.size();
    int col_size = land[0].size();

    int dp[100000][4]={0,};
    //dp[i][k] : 이전에 k 를 밟은 상태에서 i 행에서의 최댓값 
    
    //초기화
    
    int max_value = 0;
    for(int i=0;i<land[0].size();i++){
        max_value= max(max_value,land[0][i]);
    }
    
    for(int j=0;j<col_size;j++){
        dp[0][j] = max_value;
    }
    
    for(int i=1;i<row_size;i++){
        
        
        for(int k=0;k<col_size;k++){ // 이전에 밟은 것
            
            for(int j=0;j<col_size;j++){ // 이번 턴에 선택할 것 
                
                if(k==j){  // 같은 열은 연속해서 밟지 못함.
                    continue;
                }
                 dp[i][k] = max(dp[i-1][j]+land[i][j],dp[i][k]);
            }

            
        }
     
    }
 
    for(int i=0;i<col_size;i++){
        answer = max(answer,dp[row_size-1][i]);
    }
    return answer;
}