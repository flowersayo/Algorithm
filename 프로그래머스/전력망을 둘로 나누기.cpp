#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
    
#define INF 987654321

vector<vector<int>> graph;
vector<int> visited;

int bfs(int start,int n){
    
    int total_num_of_area = 1;
    
    queue<int> q;
    
    q.push(start);
    visited[start]=true;
    
  
    
    while(!q.empty()){
        
        int node = q.front();
        q.pop();

        for(int i=1;i<=n;i++){
            
            if(visited[i] || !graph[node][i]){
                continue;
            }

            visited[i]=true;
            total_num_of_area++;
            q.push(i);
        }
        cout<<"\n";
    }
    
    return total_num_of_area;
    
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INF;

    graph.assign(n+1,vector<int>(n+1,0));

    
        for(int i=0;i<wires.size();i++){
        
        int p1 = wires[i][0];
        int p2 = wires[i][1];

        graph[p1][p2]=true;
        graph[p2][p1]=true;
            
        }
    
    for(int i=0;i<wires.size();i++){
        
        int p1 = wires[i][0];
        int p2 = wires[i][1];
        
        // 간선 연결 끊기
        graph[p1][p2]=false;
        graph[p2][p1]=false;
        
        vector<int> size_of_area;
        visited.assign(n+1,0);
        
        
        for(int i=1;i<=n;i++){
            if(visited[i]){
                continue;
            }
            int size = bfs(i,n);
            
            size_of_area.push_back(size);
            
        }
         answer = min(answer,abs(size_of_area[0]-size_of_area[1]));

        
        graph[p1][p2]=true;
        graph[p2][p1]=true;
    }
    
    
    
    return answer;
}