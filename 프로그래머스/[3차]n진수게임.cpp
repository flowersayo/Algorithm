#include <string>
#include <vector>
#include <iostream>
#include <map>


using namespace std;

string toBaseK (int n, int k){ 
    
    if(n<k){  
        
        if(n >= 10){ 
        	char temp = 'A'+ (n-10);
            return string(1,temp);
        }
        return to_string(n);
    }
    

    int quotient = n/k;
	int mod = n%k;
    
    char char_mod = '0'+ mod;

  
    if(mod >= 10){ 
     char_mod = 'A'+ (mod-10) ;
    }
 	
     
    return toBaseK(quotient,k) + char_mod ; 
 }


string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int target = p;
    
    string temp ="0";
    for(int i=1;i<t*m;i++){
        string converted = toBaseK(i,n);
        temp+=converted;
    }

    int idx=p-1;
    while(t--){
        answer+=temp[idx];
        idx+=m;
    }
    return answer;
}