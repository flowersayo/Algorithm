#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
[최고의 집합]
https://school.programmers.co.kr/learn/courses/30/lessons/12938

! n은 1 ~ 10,000 범위를 지니므로 dfs로 풀려고 하면 시간초과

n = n(n-k) = n^2 - kn 이라고 하면 k값이 작을 수록,
즉 수의 격차가 작을수록 곱이 커진다. (= 최대한 수들이 균등해야한다.)

따라서 target sum 을 n 으로 나누었을 때 몫을 기본값으로 하고,
거기서 target sum 을 n 으로 나누었을 때 나머지 값만큼 각각의 항에 1씩 더해준다.

! 끝부터 더해주면 따로 정렬을 해줄 필요가 없다.

? target sum 을 만들 수 없는 경우는 어떻게 판단?
  =n>s 이면 만들 수 없다.
  
 
*/

vector<int> arr;




vector<int> solution(int n, int s) {
  	
    
    if(n>s){
        return {-1};
    }
    vector<int> answer;
    
    int quotient = s / n ;
    int remaindar = s % n;
    
    for(int i=0;i<n;i++){
        answer.push_back(quotient);
        
    }
    
    for(int i=0;i<remaindar;i++){
        answer[n-1-i]+=1;
    }
        
    
    
    return answer;
}