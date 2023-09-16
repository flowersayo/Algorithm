/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;


int count(int n,int m,vector<vector<char>>& board){
    
     vector<vector<bool>> visited(n,vector<bool>(m,0));
     
     int cnt = 0 ;
     
     for(int i=0;i<board.size();i++){
         for(int j=0;j<board[i].size();j++){
             
             if(visited[i][j]){
                 continue;
             }
             
             cnt++;
             
             int cr=i,cc=j;
             
             if(board[i][j]=='-'){ // 좌우 확인
             
                 
                 //오른쪽
                  while(board[cr][cc]=='-'){
        
                        visited[cr][cc]=1;
                        cc++;
                        if(cc>=m){
                            break;
                        }
                 }
                 
                 
             }
             else{ // '|'

                 // 아래쪽
                  while(board[cr][cc]=='|'){
        
                        visited[cr][cc]=1;
                        cr++;
                        if(cr>=n){
                            break;
                        }
                 }
                 
             }
         }
     }
     
     
     return cnt;
    
}

int main()
{
    int n,m;
    
    cin>>n>>m;
    vector<vector<char>> board(n,vector<char>(m,' '));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    
    cout<<count(n,m,board);
    
    return 0;
}