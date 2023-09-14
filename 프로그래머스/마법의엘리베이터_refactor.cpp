#include <string>
#include <vector>
#include <iostream>


using namespace std;
/**
[마법의 엘리베이터]
https://school.programmers.co.kr/learn/courses/30/lessons/148653

일의 자리를 빼서 0으로 만들었을 때 vs 일의 자리를 더해서 0으로 만들었을 때 를 비교해가며
최솟값인 경우를 선택. 

ex) 1454 를 0으로 만들기 위해 필요한 최소 값 = 
min(145 을 0으로 만들기 위해 필요한 최소 값 + 4 , 146 을 0으로 만들기 위해 필요한 최소 값 + 6);


초기 수에서 일의 자리를 0으로 만들고 계속 10으로 나누다 보면 언젠가 그 몫이 1이하 가 되는 경우가 나온다.
따라서 종료조건은 num <= 1 일때이고, num 만큼 그대로 반환해준다.
num == 1 일때 본 과정을 반복하면 무한 루프에러가 생길 수 있어서 종료조건에 꼭 포함한다.
(1-> 1 + 9 = 10/10  -> 1 ... ) 

*/


using namespace std;


int sol(int num) {
    if(num <= 0 ) return  num; 
    int a = num % 10, b = 10 - num % 10;
    return min(sol((num-a)/10)+a, sol((num+b)/10)+b);
}

int solution(int storey) {

    return sol(storey);
}