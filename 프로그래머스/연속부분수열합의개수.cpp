#include <string>
#include <vector>
#include <set>
#include <iostream>


using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    
    set<int> s;
    
    int size = elements.size();
    
   for(int i=0;i<size;i++){ // i : 덧셈 시작점
       
       int sum =0;
       for(int j=0;j<size;j++){ // i 부터 i+j까지 더해가는 과정에서 나온 중간 합들을 모두 insert 
           sum+=elements[(i+j)%size]; 
           s.insert(sum);
       }
       
   }
    return s.size();
}