#include <string>
#include <vector>
#include <iostream>

using namespace std;


int gcd(int a,int b){
    
    if(b==0) return a;
    else return gcd(b,a%b);
    
}

int getGCD(vector<int> array1,vector<int> array2){
    
    
    int gcd_value =array1[0];
    
    for(int i=1;i<array1.size();i++){
        gcd_value = gcd(gcd_value,array1[i]);
    }
    
     
    for(int i=0;i<array2.size();i++){
        
        if(array2[i] % gcd_value ==0){ // 나눠지는 값이 있을 경우
            return 0;
        }
    }
    
    return gcd_value;
}

/**
[숫자 카드 나누기]
https://school.programmers.co.kr/learn/courses/30/lessons/135807

	하나의 배열에 여러개의 원소에 대해 최대공약수 구하기.

	a b c 의 최대공약수를 구하는 법?
    
    특정 수가 최대공약수임을 가정하고 모든 수를 나눠보는 것은 최대 O(1억) 의 시간이 소요되므로 시간초과 우려가 있다.
    따라서 a b 의 최대 공약수를 먼저 구하고 그 값을 k라고 하면, k와 c의 최대 공약수를 구해준다.
    이 때 두 수의 최대 공약수를 구하기 위해서 O(logN)의 유클리드 호제법을 사용한다.
    
    
    ? 최대 공약수로만 확인해보면 되는 이유 ? 
    
    최대 공약수로 나머지 배열들의 원소들을 나눠보았을 때 나누어지는 원소가 있다면,
    그 최대 공약수의 약수로 이루어진 원소들로 나눌때에도 당연히 나누어지는 원소가 있다.

*/
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer;
    
      answer = max(getGCD(arrayA,arrayB),getGCD(arrayB,arrayA)); // 최댓값 갱신
    
    return answer;
}