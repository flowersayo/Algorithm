#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/**
[뒤에 있는 큰 수 찾기]
https://school.programmers.co.kr/learn/courses/30/lessons/154539

이전 값 보다 큰 값(i)을 찾으면 여태까지의 값들(0~i)을 순회하면서
그 큰 값보다 더 작은 값들이 있다면 뒷 큰수를 갱신한다.
이 때 그 큰 값보다 더 큰 값을 만났을 때에는 반복을 종료하는데 
그 이유는 이제 그 큰 값은 처음으로 나오는 가장 큰수가 아니게 되기 때문이다.

*/
vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(),-1);
    
  for(int i=0;i<numbers.size();i++){ // i 의 뒷 큰 수 찾기
      
      int top_pointer = i-1 ; // 스택 포인터
      

      if(numbers[top_pointer] < numbers[i]){ // 더 큰 값을 찾으면
          
          int backtracking_idx =0;
          while(numbers[top_pointer-backtracking_idx] < numbers[i]){ // 값이 더 클 동안
              
              if(answer[top_pointer-backtracking_idx]==-1){ // 아직 이거보다 큰 수가 한번도 나오지 않았을 경우
                  answer[top_pointer-backtracking_idx]=numbers[i];
              }
             
              backtracking_idx++;
          }
      }
      
      
  }

    return answer;
}