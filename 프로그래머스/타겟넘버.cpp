#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer=0;
void dfs(int depth,int target, char sign,int sum,vector<int> numbers){
    
    int new_sum=sum;
  
	if(sign =='+'){
        new_sum += numbers[depth];
    }
    else if(sign=='-'){
        new_sum-=numbers[depth];
    }
    
     if(depth == numbers.size()-1){
            
         if(new_sum==target ){
             answer++;
         }
         return; 
    }
    
    
    dfs(depth+1,target,'+',new_sum,numbers);
    dfs(depth+1,target,'-',new_sum,numbers);
    
  
	
}

int solution(vector<int> numbers, int target) {
    
    dfs(-1,target,'*',0,numbers);
  
    return answer;
}