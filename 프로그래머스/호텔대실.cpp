#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


typedef pair<int,int> ci;

int convertToInt(string s,string type)
{
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));
    
    
    if(type=="end"){
        return hour * 60 + minute+10;
    }

    return hour * 60 + minute;
}
/*
호텔 대실

*/
int solution(vector<vector<string>> book_time) {
    vector<ci> v;
    
    for (vector<string> time : book_time)
    {
        int start = convertToInt(time[0],"start");
        int end = convertToInt(time[1],"end");
        
        v.push_back({start, 1}); // 회의가 시작하므로 +1
        v.push_back({end, -1}); // 회의가 종료되므로 -1
    }
    
    sort(v.begin(), v.end()); // 시작시간 기준 정렬
    
    int cnt = 0; //현재 동시에 진행중인 회의 개수 
    int answer = 1;
    for(int i=0;i<vx.size();i++){
        
        cnt+= v[i].second;
        answer = max(cnt, answer);
    }
  
    return answer;
}