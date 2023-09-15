#include <string>
#include <vector>
#include <iostream>

using namespace std;


const int MOD = 1000000007;
/**
[등굣길]
https://school.programmers.co.kr/learn/courses/30/lessons/42898


dp[i][j] : i행 j열 까지 도달할 수 있는 경우의 수를 저장


dp[i][j] 에 도달하기 위한 경우의 수 = 왼쪽칸까지 도달하는 경우의 수 + 위쪽칸까지 도달하는 경우의 수


! 웅덩이가 i행 1열, 1행 i 열에 있을 수 있음에 유의
*/
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int>> dp (n+1,vector<int>(m+1,0)); 
    
    
	dp[1][1]=1;
    
     for(auto puddle : puddles){
         dp[puddle[1]][puddle[0]]=-1; // 웅덩이 표시
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
              
            if(i==1 && j==1){
                continue;
            }
          
            if(dp[i][j]==-1){
                dp[i][j]=0;
           
                continue;
            }
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            
            
          
         
             
        }
    }
    
    
    answer = dp[n][m];
    return answer;
}