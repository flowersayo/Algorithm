#include <string>
#include <vector>
#include <iostream>

using namespace std;


// 처음부터 검사하면서 str[i] < str[i+1] 이라면 i를 지운다.
// ! 주의 : 같은 숫자로 이루어져 있거나, 내림차순 정렬된 경우에도 숫자를 지워야함.
string solution(string number, int k) {
    
    for(int i=0;i<k;i++){
        
        
        bool check=true;
        for(int j=0;j<number.length()-1;j++){
                    
            if(number[j]<number[j+1]){
                number.erase(number.begin()+j);
                
                check=false;
                break;
            }
          
            
        }
        
        if(check){ // 모든 수가 같다면 가장 뒷자리 수를 지운다.
            number.erase(number.begin()+number.size()-1);
        }
        
        
    }
    return number;
}