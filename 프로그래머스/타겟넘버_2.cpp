#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
https://school.programmers.co.kr/learn/courses/30/lessons/43165

비트 마스킹 풀이 

+와 -를 나열하는 경우의 수를 구하는 것은 n 자리 중 + 가 들어갈 자리를 선택하는 조합과 같다.
따라서 1 : - 선택 , 0 : + 선택 으로 간주하고 비트마스킹을 통해 모든 조합을 시도해볼 수 있다.

*/

int solution(vector<int> numbers, int target) {

    int answer=0;
    
 int size = 1<<numbers.size(); 
 for(int i=0;i<size;i++){
     
     int sum=0;
    for(int j=0;j<numbers.size();j++){
        
        if(i & (1<<j)){ // i 의 j 번째 비트가 1이면 
            sum+=numbers[j];
        }
        else{
            sum-=numbers[j];
        }
    }
     
     if(sum==target){
         answer++;
     }
     
 }
  
    return answer;
}