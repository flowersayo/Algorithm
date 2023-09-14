#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


vector<int> preorder_list;
vector<int> postorder_list;

bool cmp(vector<int> v1,vector<int> v2){
    
    if(v1[1]!=v2[1]){ // y 좌표 내림차순
        return v1[1]>v2[1];
    }
    
   
}

struct Node {
    
    Node* left =  NULL;
    Node* right =  NULL;
    int x;
    int y; 
    int n;
};

Node* insert (Node* root, Node* node){ // node: 삽입할 노트


    if(root == NULL){ // 비어있는 칸을 만나면 노드 리턴  
        return node;

    }
    
    if(root->x < node->x ){ // node 의 x값이 더 크면 
        
    	 root->right = insert(root->right,node);
    }
    else{ // node의 x값이 더 작으면
         
         root->left = insert(root->left,node);
    }
    
    return root;
    
}

void preorder(Node* node){ // 전위 순회
    
    
    if(node==NULL){
        return;
    }

    preorder_list.push_back(node->n); 
    cout<<node->n<<" ";

    preorder(node->left);
    preorder(node->right);
        
    
}

void postorder(Node* node){ // 후위 순회
    
     
    if(node==NULL){
        return;
    }

    postorder(node->left);
    postorder(node->right);
    postorder_list.push_back(node->n); 
        
}
/**
[길 찾기 게임]
https://school.programmers.co.kr/learn/courses/30/lessons/42892

1. 트리 생성

y좌표가 큰 노드부터 위에서 내려오면서 하나씩 삽입하면서 트리를 만든다.

- 임의의 노드 V의 왼쪽 서브 트리(left subtree)에 있는 모든 노드의 x값은 V의 x값보다 작다.
- 임의의 노드 V의 오른쪽 서브 트리(right subtree)에 있는 모든 노드의 x값은 V의 x값보다 크다.

이때, 다음 조건을 따르므로 data는 "x값 기준"으로 이진트리에 insert를 하면 
자연스럽게 x값 기준 이진탐색트리로 구성이 된다.



2. 전위 순회, 후위 순회 

전위 순회 : root -> left -> right
후위 순회 : left -> right -> root

*/
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
   
    
    
 	vector<vector<int>> answer;
    
    
    for(int i=0;i<nodeinfo.size();i++){
        nodeinfo[i].push_back(i+1);// 자신의 번호를 [2] 에 저장 
    }
    
    sort(nodeinfo.begin(),nodeinfo.end(),cmp);
    
    Node * root = new Node();
    
     root->x=nodeinfo[0][0];
       root->y=nodeinfo[0][1];
        root->n=nodeinfo[0][2];
    
    for(int i=1;i<nodeinfo.size();i++){
        
        Node* new_node = new Node();
        
        new_node->x=nodeinfo[i][0];
        new_node->y=nodeinfo[i][1];
        new_node->n=nodeinfo[i][2];
        

        insert(root,new_node);
    }
    

    preorder(root);
    postorder(root);
    

    answer.push_back(preorder_list) ;
    answer.push_back(postorder_list) ;
    
    return answer;
}