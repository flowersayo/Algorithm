#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
/**
[요격 시스템] refactoring.ver.
https://school.programmers.co.kr/learn/courses/30/lessons/181188#

어떤 미사일(s,e)이던 제거하려면 최소 s ~ e 중에서 한번은 요격해야함.
그렇다면 하나의 미사일을 요격할 때 최대한 다른 미사일들이 많이 overlap되도록 하면 좋음!
특정 타겟 미사일을 기준으로 다음 미사일을 보면서 요격범위를 좁혀감.
그러다가 범위가 전혀 겹치지 않는 미사일을 만나면 그 범위에서 미사일쏘고 다음 타겟 미사일로 변경함.


tip! 시작범위 기준이 아닌 끝 범위 기준 오름차순 정렬을 해주면 코드가 조금 더 간단해진다

시작 범위 기준 오름차순 정렬은 다음 미사일이 나왔을 때, 시작과 끝을 모두 업데이트 해주어야함.
그러나 끝 범위 기준 오름차순 정렬을 수행하게 되면 다음 미사일의 시작점만 현재 요격범위에 들어오는지 확인해주면 된다.
어짜피 다음 미사일의 끝지점은 현 미사일 보다 뒤에 있으니까 현재 요격범위가 가장 최소 범위일 때이다. 

*/

bool cmp(vector<int> v1, vector<int> v2){
    
    return v1[1]<v2[1]; // 끝지점 기준 오름차순 정렬
}
int solution(vector<vector<int>> targets) {
    int answer = 0;

    sort(targets.begin(),targets.end(),cmp); // 오름차순 정렬 
     
    int t=-1;
    
    for(auto &target : targets){
        if(target[0]>=t){ // 다음 미사일의 시작지점이 현 미사일의 끝지점보다 크면 (= 범위가 겹치지 않음)
            answer++;
            t=target[1];
        }
    }
    
    return answer;

}