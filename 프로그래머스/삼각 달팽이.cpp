#include <string>
#include <vector>
#include <iostream>

using namespace std;



void fill(int n,int depth,int number,int cx, int cy, vector<vector<int>>& board){

    int size = n - (depth*3)-1; // depth 일때 삼각형 한 변의 길이 

     if( number > (n * (n+1)/2)){
        return;
    }
    
    if(size==0){
        
        board[cy][cx]=number;
        return;
    }
   
    for(int i=0;i<size;i++){

       board[cy++][cx]=number++;
             if(number > (n * (n+1)/2)){
        return;
    }
    
    }


    for(int i=0;i<size;i++){

        board[cy][cx++]=number++;  
        if(number > (n * (n+1)/2)){
        return;
    } 
       
    }


    for(int i=0;i<size;i++){
        
        board[cy--][cx--]=number++;     
        
    }

    cy++;cx++;
    fill(n,depth+1,number,cx,cy+1,board);

}
/**
[삼각 달팽이]
https://school.programmers.co.kr/learn/courses/30/lessons/68645

2차원 배열 공간에 삼각형을 재귀적으로 그려나가자!

하나의 삼각형은 아래, 오른쪽 , 왼쪽 위 선분으로 구성 되어있다.
depth는 몇번째 삼각형을 그리고 있는지를 의미한다.

이때, N-1번째 칸의 한 변의 길이는 맞닿은 (바깥쪽 삼각형의 한변의 길이 -1)이고
따라서 안쪽 삼각형의 한변의 길이는 (바깥쪽 삼각형의 한변의 길이 -1)에서 바깥쪽 삼각형의 테두리를 제외한 
(바깥쪽 삼각형의 한변의 길이 -1 -2)가 된다.
depth가 깊어질 수록 그려지는 안쪽 삼각형의 크기는 3씩 줄어든다. 
따라서 size = n - (depth*3)-1 라는 공식을 유도할 수 있다.

여기서 size를 구하기 위해서 -1을 빼준 이유는 
예를 들어 한 변의 길이가 3인 삼각형의 전체 크기는 6이된다.
이 삼각형을 아래(2칸) 오른쪽(2칸) 왼쪽위(2칸) 으로 나눠 그리기 위해서 1을 더 빼주었다.

*/
vector<int> solution(int n) {
    
    vector<vector<int>> board (n,vector<int>(n,0));
    vector<int> answer;
    fill(n,0,1,0,0,board);
    

    for(int i=0;i<board.size();i++){
        for(int j=0;j<i+1;j++){
            answer.push_back(board[i][j]);
        }
    }

    return answer;
}
