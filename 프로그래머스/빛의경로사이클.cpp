#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


// idx : 상 우 하 좌 ( 시계 방향 )
int dr[4] = {1,0,-1,0};
int dc[4] = {0,1,0,-1};

int visited[500][500][4] = {false}; // 각 점에 대한 상하좌우 경로 방문 여부


typedef pair<int,int> ci;

int calDir(char dir,int cur){
    
    if(dir =='S'){
        return cur;
    }
    else if(dir =='L'){
        
        return (cur+4-1)%4;
    }
    else if(dir =='R'){
        
        return (cur+1)%4;
    }
}

int dfs(int cnt,int cr,int cc,int dir,vector<string> grid){
    
    
    // 이전점에서 빛을 쏜 위치 -> 다음점에서 빛을 쏠 위치 반환
    int row_size = grid.size();
    int col_size = grid[0].size();
    
    while(true){
        
        visited[cr][cc][dir]=true;

        // 다음 이동 좌표 
        int nr = (cr + dr[dir] + row_size) % row_size; // 격자의 끝을 넘어갈 경우 처리
        int nc = (cc + dc[dir] + col_size ) % col_size;

        // 다음 좌표에서 빛을 쏘는 방향
        int nd = calDir(grid[nr][nc],dir);
        
           //cout<<"cr :"<<cr<<" "<<"cc :"<<cc<<"dir :"<<dir<<" "; 
    
    //cout<<"nr:"<<nr<<"nc:"<<nc<<"nd :"<<nd<<"\n";
         if(visited[nr][nc][nd]){ // 방문 했던 곳으로 다시 돌아오면
       
        	break;
    	 }
        
        cr=nr;
        cc=nc;
        dir =nd;
        cnt++;
 
        
    }
    
    return cnt;
  
}
/**
[빛의 경로 사이클]
https://school.programmers.co.kr/learn/courses/30/lessons/86052


1. 빛은 어디에서 쏘든 쐈던 위치로 되돌아온다. ( 모든 정점이 연결되어 있는 형태 )
=> 어떤 경로에서 시작하던 무조건 사이클을 이루게 되어있음.

2. 각각의 사이클은 중복되는 경로를 포함할 수 없다.
한 위치에 빛이 들어오면 해당 위치에서 나가는 빛의 방향은 항상 일정하다.
따라서 중복이 있다면 결국 해당 사이클과 같아지기 때문에 서로 다른 사이클이라면 경로가 중복이 될 수 없다.

? 어떻게 서로 다른 사이클을 구별 ? 
=> 방문했던 경로를 방문체크해주는 것이 중요 !

각각의 격자점에 대해 상,하,좌,우 방향으로 빛을 쏠 수 있으므로
빛의 이동경로를 저장하기 위해 grid 2차원 배열에 4개의 데이터를 저장한다. 
빛의 특성 때문에 들어가는 경로, 나오는 경로 중 나오는 경로만 체크해도 된다.

3. 시간초과를 방지하기 위하여 재귀 -> while 문으로 리팩토링!

재귀함수 쓰면 스택 오버플로우(Stack Overflow) 시간초과 발생 
최대 재귀 깊이가 500 * 500 * 4 까지 될 수 있어서 그런 것 같다.


*/

vector<int> solution(vector<string> grid) {
    
    vector<int> answer;

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){

            for(int d=0;d<4;d++){
                
                if(!visited[i][j][d]){ // 아직 방문하지 않았다면

                   int cnt = dfs(1,i,j,d,grid);
                    answer.push_back(cnt);
                }

               
            }
           
        }
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}