#include <string>
#include <vector>

using namespace std;


int answer =0;
int visited[8]={false}; // 던전 방문 여부

void permutation(int fatigue, int cnt, vector<vector<int>> dungeons){ //cnt : 방문한 던전의 수
    
    if(fatigue < 0){
        return;
    }
  
    
    answer = max(answer,cnt);
    
    if(cnt == dungeons.size()){
        return;
    }
    
    for(int i=0;i<dungeons.size();i++){
        
        if(visited[i] ){
            continue;
        }
        
        if(dungeons[i][0]<=fatigue){ // 최소 피로도 만족
            
            int cost = dungeons[i][1]; // 던전 도는데 필요한 피로도 비용
            visited[i]=true;
            permutation(fatigue-cost, cnt+1, dungeons);
            visited[i]=false;
        }
        
    }

}

int solution(int k, vector<vector<int>> dungeons) {
 
    permutation(k,0,dungeons);
    
    return answer;
}