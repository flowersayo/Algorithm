#include <stack>
#include <map>
#include <iostream>

using namespace std;

//괄호의 짝을 저장할 맵
map <char, char> bracket;


//짝이 맞는 괄호쌍들을 모두 제거
void removePair(stack <int> &s,string input) {

    //스택에 넣고, 스택 top과 짝이 맞을때 pop한다.
 
    for (int i = 0; i < input.size(); i++) {

        switch (input[i]) {
        case '{' : //여는 괄호
            s.push(input[i]);
            break;

        case '}': //닫는 괄호
            if (!s.empty() && s.top() == bracket[input[i]])
                s.pop();

            else  s.push(input[i]); //스택이 비어있거나 짝이 맞지 않을경우


        }
    }

}

//stack에서 괄호를 두개씩 꺼내며 필요한 연산횟수 카운트
int count(stack <int>& s) {
    int cnt = 0; // 연산횟수

    while (!s.empty()) {
        
        char c1 = s.top();

        if (c1 == '{')
            cnt++;
        s.pop();

        char c2 = s.top();

        if (c2 == '}')
            cnt++;
        s.pop();
    }

    return cnt;
}

int main() {

   
    int ans;
    string input;
    bracket['}'] = '{';
    int cnt = 1;

    while (true) {

        stack <int> s;

        //입력
        cin >> input;
        if (input.find('-')!= string::npos)
            break;

        //연산
         removePair(s,input);


         cout << cnt<<". "<<count(s)<<'\n';
         cnt++;
       
    }
}