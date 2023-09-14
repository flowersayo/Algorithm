#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

// 이분 탐색을 이용하여 가장 최소시간을 찾자.

using namespace std;


long long solution(int n, vector<int> times) {
    long long answer =  (long long) n *times[times.size()-1]; // 심사관 중 최대 심사 시간 * 인원수
    long long  left = 1;
    
   long long right = (long long) n *times[times.size()-1]; // 심사관 중 최대 심사 시간 * 인원수
    
    long long mid;
    while(left<=right){
        

       mid = (left + right )/2;

        long long x=0 ; // 만족되는 사람 수 
        
        for(int i=0;i<times.size();i++){
            x += mid/times[i];
        }
        
        if(x>=n){ // 만족되는 사람수가 더 많으면 시간 조금 더 줄임
            right =mid-1;
            answer = min(answer,mid);
        }
        else {
            left = mid+1;
        }

   
    }
    return answer;
}