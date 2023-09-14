#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;



/**
두 큐 합 같게 만들기
https://school.programmers.co.kr/learn/courses/30/lessons/118667

그리디식 접근

처음 주어진 queue1의 합을 L, queue2의 합을 R이라고 했을 때,
L과 R을 같게 만들기 위해서는 다음과 같은 탐욕법을 사용하여 해결할 수 있다.

증명은 https://tech.kakao.com/2022/07/13/2022-coding-test-summer-internship/ 참고

🔑 KEY POINT 
어떤 방법으로도 각 큐의 원소 합을 같게 만들 수 없는 경우라고 판단하기 위해서
최소 몇번의 반복 루프를 돌아야할까? 


! 합을 계산하는 과정에서 overflow 유의 

*/

int getSum(deque<int> deque){

    long long  sum=0;
    
    for(int i=0;i<deque.size();i++){

        sum+=deque[i];
    }

    return sum;
}

int equalify(deque<int> deque1, deque<int> deque2){

    int cnt = 0;
    int temp = 0;
    
    int total_number_of_both_queue = deque1.size()+deque2.size();
    
    long long q1_sum = getSum(deque1);
    long long q2_sum = getSum(deque2);
    
	if((q1_sum + q2_sum)%2==1){
        return -1;
    }

    cout<<"q1_sum :"<<q1_sum<<"q2_sum"<<q2_sum<<"\n";

    while(q1_sum != q2_sum){

		cnt++;
        temp++;
        
        if(temp == total_number_of_both_queue*4){
            return -1;
        }
        
        
        if(q1_sum > q2_sum){ // q1 -> q2 

            int temp = deque1.front();
            deque1.pop_front();
            deque2.push_back(temp);
            q1_sum -= temp;
            q2_sum += temp;

        }
        else if(q1_sum < q2_sum){  // q2 -> q1

            int temp = deque2.front();
            deque2.pop_front();
            deque1.push_back(temp);
            q2_sum -= temp;
            q1_sum += temp;


        }

    }
    
    return cnt;


}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    
    
 	deque<int> deque1;
    deque<int> deque2;
    
    for(int i=0;i<queue1.size();i++){
    	deque1.push_back(queue1[i]);
    }
    
    for(int i=0;i<queue2.size();i++){
    	deque2.push_back(queue2[i]);
    }
    
    answer = equalify(deque1,deque2);

    return answer;
}