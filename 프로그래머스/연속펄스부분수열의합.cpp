#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
/*
[연속 펄스 부분 수열의 합]
https://school.programmers.co.kr/learn/courses/30/lessons/161988

모든 부분 수열을 구해서 펄스수열을 직접 곱하려고 하면 시간초과! 
=> 다른 접근법 필요

특정 범위의 부분 수열에서 펄스 수열을 곱해서 나올 수 있는 경우의 수는 총 두가지!
1. [-1,1,..] 로 시작하는 펄스수열을 곱한 경우
2. [1,-1,..]  로 시작하는 펄스수열을 곱한 경우

연속 펄스 부분 수열의 합 중 가장 큰 것을 찾는다.
=> 펄스 수열을 곱한 수열에서 연속한 최대 부분 수열의 합을 구한다.

연속 부분 수열의 최대합을 구하는 알고리즘은 여러가지가 있다.
그 중 O(n) 의 시간복잡도를 지니는 DP로 해결할 수 있는데,
dp[i] = i 로 끝나는 연속 부분 수열의 최대 합
이라고 가정하면 dp[i] = max(i번째 원소,dp[i-1]+i번째 원소) 임을 활용한다.

!자료형 유의! 
dp 에서 누적합을 구하는 과정에서 오버플로우 날 수 있으므로 long long 자료형 사용 



*/

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    int size = sequence.size();
    
     if(size==1){
         return max(sequence[0],-sequence[0]);
        
    }
    vector<long long> sequence1(size,0); // 1로 시작
    vector<long long> sequence2(size,0); // -1로 시작
    
    for(int i=0;i<size;i++){
       sequence1[i]=sequence2[i] = sequence[i];

    }
    

    for(int i=0;i<size;i++){
        sequence1[i] *= (i % 2 == 0 ? 1 : -1);  // 짝수일때 1, 홀수일때 -1
        sequence2[i] *= (i % 2 == 0 ? -1 : 1); // 짝수일때 -1, 홀수일때 1
        
    }
    
    // 연속 최대 부분 수열의 합 구하기
	
    vector<long long> dp1 (size,0); // i 로 끝나는 연속 부분 수열의 최대 합
    vector<long long> dp2 (size,0); // i 로 끝나는 연속 부분 수열의 최대 합

    dp1[0]=sequence1[0];
    dp2[0]=sequence2[0];
    
    for(int i=1;i<size;i++){
        
      //  cout<<"sequence1[i] :"<<sequence1[i]<<"dp1[i-1]+sequence1[i]:"<<dp1[i-1]+sequence1[i]<<" \n";
        dp1[i] = max(sequence1[i], dp1[i-1]+sequence1[i]); 
        dp2[i] = max(sequence2[i], dp2[i-1]+sequence2[i]);
    
        //cout<<i<<" "<<dp1[i]<<" "<<dp2[i]<<"\n";
        long long temp = max(dp1[i], dp2[i]);
        answer = max(answer,temp);
    }
    

  
    return answer;
}