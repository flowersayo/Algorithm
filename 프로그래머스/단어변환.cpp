#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int INF = 51;
int answer = INF;

vector<int> visited;

 // 서로 다른 알파벳의 개수 
int stringDiff(string str1, string str2){
    
    int cnt =0;
    for(int i=0;i<str1.length();i++){
       if(str1[i]!=str2[i]){
           cnt++;
       }
    }
    
    
    return cnt;
}

void dfs(int cnt,string current,string target, vector<string> words){
    
    if(current==target){
        answer = min(answer,cnt);
        return;
    }
    
	for(int i=0;i<words.size();i++){
       
       if(visited[i]){
           continue;
       }
        
       if(stringDiff(current,words[i]) ==1){
    		visited[i]=true;
            dfs(cnt+1,words[i],target,words);
            visited[i]=false;
       }
   }
    
    
}
/**
[단어변환]
https://school.programmers.co.kr/learn/courses/30/lessons/43163

아래와 같은 규칙을 이용하여 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾는 문제! 

1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
2. words에 있는 단어로만 변환할 수 있습니다.

=> dfs 를 통해 target 까지의 단어변환을 진행한다.
=> 이때, words 중 차이가 1인 알파벳들로만 변환을 진행한다.

*/
int solution(string begin, string target, vector<string> words) {
    
    visited.assign(words.size(),0);
    dfs(0,begin,target,words);
    
    if(answer==INF){
        return 0;
    }
    return answer;
}