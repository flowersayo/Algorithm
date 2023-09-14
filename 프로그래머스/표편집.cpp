
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct Node{

    int data;
    Node* next; // 다음 노드의 주소
    Node* prev; // 이전 노드의 주소

};


string edit(int n, int k, vector<string> cmds, vector<Node*> & nodes){
    
    string exist; // 각 행의 존재 여부
    
    for(int i=0;i<n;i++){
        exist+="O"; 
    }
    
    
    Node* current = nodes[k]  ; // 현재 가리키고 있는 노드. 
    stack<Node*> deleted; // 삭제된 노드들 
    
    for(auto cmd : cmds){

        int move_cnt;
        
        switch(cmd[0]){
                
            case 'D': 
  
               move_cnt = stoi(cmd.substr(2));
                
                while(move_cnt--){
                    current = (current->next);
                }
             	
                break;
                
            case 'U':
                
           	
                move_cnt = stoi(cmd.substr(2));
                
                while(move_cnt--){
                     current = (current->prev);
                }
                
                break;
                
            case 'C': // 삭제 
               
                
                exist[current->data] = 'X';
                deleted.push(current);
         
                if(current->next){ 
      
                   current->next->prev = current->prev;
             	
                }
               if(current->prev){ 
                    
               		 current->prev->next = current->next;
                 	         
                }
                
                if(current->next){ // 다음 행이 있으면
                    current = current->next;
                }else{
                    current = current->prev;
                }

                break;
            case 'Z': //  복구 (맨 앞이거나 맨 끝인경우 인덱스 에러 유의) 
 				
                
                Node* latest_deleted = deleted.top();
                deleted.pop(); 
	
                // 제거된 행 복구
                exist[latest_deleted->data] = 'O';
                
                
				if( latest_deleted->prev){
                    latest_deleted->prev->next=  latest_deleted;
                }
                
                if(latest_deleted->next){
                    latest_deleted->next->prev = latest_deleted;
                }
                
              
        }

    }
    
	return exist;
    
}
/**
[표 편집]
https://school.programmers.co.kr/learn/courses/30/lessons/81303#


5 ≤ n ≤ 1,000,000 , 1 ≤ cmd의 원소 개수 ≤ 200,000 이므로 
일반 배열을 사용하게 된다면 원소하나를 지울때마다 나머지 원소들을 한칸씩 앞으로 당겨줘야 하므로 시간이 오래걸린다. 
=> Linked List 를 활용한다! 

! 삭제했던 노드를 복구할 때, 복구된 노드의 prev와 next는 새롭게 업데이트 해주지 않아도 된다.
스택 자료구조에 의해(FILO), 가장 최신 노드부터  그 노드가 살아있을 때의 상태를 그대로 기억하고 있기 때문에.

구조체 배열을 객체 그 자체로 관리하면 통과를 못하는데.. 
구조체 배열을 포인터로 관리하니까 통과했다ㅠ ( 이거 때문에 3일동안 고민함.. ) -> 이유가 뭐지..?!

*/
string solution(int n, int k, vector<string> cmd) {

    string answer = "";
 
    vector<Node*> nodes(n); 

     for(int i = 0; i < n; i++){  
         nodes[i] = new Node();
         nodes[i]->data = i;
    }

    // 이전 - 다음 노드 초기화
    for(int i = 0; i < n; i++){
        if(i > 0){
            nodes[i]->prev = nodes[i - 1];
        }
        if(i < n - 1){
            nodes[i]->next = nodes[i + 1];    
        }
    }

    answer = edit(n,k,cmd,nodes);

   

    return answer;
}