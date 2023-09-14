#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    for(auto v : s)
    {
        int t = 0;
        int c = v - 'a'+1 ; // 문자 -> 숫자 ex) a는 0으로 b는 1로 
        
        do{
            v = (c % 26) + 'a'; // 숫자 -> 문자 
            if(skip.find(v) == string::npos)
            {
                t++;
            }
            c++; // 다음 문자로
        }
        while(t < index);
       
        answer += v;
    }
    return answer;
}
