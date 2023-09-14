#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

// 문자열을 구분자 delimiter 기준으로 자른 토큰들을 반환
vector<string> split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

// 양의 정수 n 을 k 진수로 바꿔주는 함수 
string toBaseK(int n, int k){

    if (n < k ){
        return to_string(n);
    }
    int quotient = (n / k) ; // 몫
    char remaindar = (n % k) +'0'; // 나머지
    
    return toBaseK(quotient,k) + remaindar;
    
}

bool isPrime(long long n){

    if(n==1){
        return false; 
    }
    for(long long i=2;i*i<=n;i++){
        
        if(n%i==0){
            return false;
        }
        
    }
    
    return true; 
}

// 0 의 위치를 마킹하고 그 사이사이에 있는 숫자들이 소수인지 판단
// x 0 a 0 b 0 c 0 
int check(string number){
    
 
    int cnt=0;
    vector<string> tokens = split(number,'0');

    for(int i=0;i<tokens.size();i++){
        
        if(tokens[i]==""){
            continue;
        }
        if(isPrime(stol(tokens[i]))){
            cnt++;
        }
        
     
    }
    
    return cnt;
}
/**
[k진수에서 소수 개수 구하기]
https://school.programmers.co.kr/learn/courses/30/lessons/92335

1. 주어진 숫자 n 을 k진수로 바꾼다.
2. 0 을 구분자로 하여 k 진수로 변환된 숫자를 쪼갠다.

< 문제 풀 때 주의할 점 >

n 을 k 진수로 바꾸었을 때 최댓값은? 
1,000,000 ~ (3의 12제곱) 이므로 10진법으로 읽는다면 10^12 즉, int 형 범위를 벗어난다.

! 따라서 변환된 수를 저장하는 자료형은 long 같은 더 큰 범위 자료형을 사용해야한다. 
! 이떄 integer overflow ( int * int , int + int ) 에도 유의한다.

! 소수 판단시 2 ~ n 까지 모든 수를 나눠보면서 소수인지 판단하면 시간초과 
=> 2 ~ n 의 제곱근 까지 나눠주기

*/
int solution(int n, int k) {
    int answer = -1;
    
    string nToBaseK = toBaseK(n,k);
    answer = check(nToBaseK);
    
    return answer;
}