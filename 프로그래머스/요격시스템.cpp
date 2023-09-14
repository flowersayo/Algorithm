#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
/**
[요격 시스템]
https://school.programmers.co.kr/learn/courses/30/lessons/181188#

어떤 미사일(s,e)이던 제거하려면 최소 s ~ e 중에서 한번은 요격해야함.
그렇다면 하나의 미사일을 요격할 때 최대한 다른 미사일들이 많이 overlap되도록 하면 좋음!
특정 타겟 미사일을 기준으로 다음 미사일을 보면서 요격범위를 좁혀감.
그러다가 범위가 전혀 겹치지 않는 미사일을 만나면 그 범위에서 미사일쏘고 다음 타겟 미사일로 변경함.


?미사일들을 시작점 기준으로 정렬해주는 것이 필요한 이유?
=> 범위가 겹치지 않은 미사일을 만났을 때, 
그 뒤에 현재 타겟 미사일의 요격범위와 겹치는 미사일이 없다는 사실을 보장하기 위해서.

*/
int solution(vector<vector<int>> targets) {
    int answer = 0;
    
  
    sort(targets.begin(),targets.end()); // 오름차순 정렬 
    
    int start = targets[0][0] , end = targets[0][1];
    
    for(int i=1;i<targets.size();i++)
    {
        if(start<=targets[i][0] && targets[i][0]< end){// 다음 미사일이 현재 요격범위 안에 들어오면 
            
            // 요격범위 업데이트 ( 시작, 끝 )
			start= targets[i][0];
            end = min (targets[i][1],end); 
            
        } 
        else{ // 벗어나면 새로운 요걱범위 갱신
            
            start = targets[i][0];
            end = targets[i][1]; 
            answer++;
        }
    }    
    return answer+1; // 마지막 벗어남 판정 받지 못한 미사일 + 1
}