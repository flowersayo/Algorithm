class Solution
{
public:
    /*
        이 문제 같은 경우는 (-2) 같은 예외 경우가 있어서 postfix 방식으로
        숫자가 들어오고 나서 앞에 있는 부호를 처리하려고 하면, (13-2), 2-3, (-2)
       중 어떤 경우인지 분별이 너무 어렵다. 따라서 -가 들어오면 사인을 인식하고
       -> 뒤에 있는 숫자에 부호를 붙여서 push 하는게 더 좋다.

       게다가 +와-는 사실상 결합 법칙이 성립해서 이 경우에는 우선순위 고려 없이
       앞에서부터 보면서 숫자가 나오면 바로 부호를 붙여나가면서 결과에 합산되도록 연산을 해도 된다.


       숫자가 나올 때마다 현재 그 숫자에 적용되는 연산자를 곱해서 계산한다.

       따라서 현재 "스코프" 에서 어떠한 부호(-,+)의 영향을 받고 있는지가 중요해진다.
       현재 스코프를 기억하기 위해서 stack 을 이용한다. stack 의 최상단에 있는 부호가 현재 값에 영향을 주는 스코프인 것이다.

       예를 들어서, -( )  같은 경우에는 - 스코프의 영향을 받게 된다.
       따라서 - (-3+5) 라는 수식이 있다면, -의 영향을 고려하여 각각 total 에 +3 -5 라는 값을 더해준다.
       이를 위해서는 부호를 만났을 때, 앞선 스코프의 값을 고려하여 앞으로의 숫자에 곱해질 적절한 부호를 구하여 stack 에 push 해주면 된다.
       ex) - * - = - , - * + = -

       다만 이 때, (3+5) 같은 경우는 연산자수와 피연산자수가 일치하지 않아서 제대로 연산이 어렵다는 문제가 있다.
       따라서 이를 해결해주기 위해서 ( 다음에 숫자가 나오는 경우에는 명시적으로 기존 스코프를 복제하여
       (3+5) -> (+3+5) 를 만들고 +3 이라는 값이 total 에 제대로 더해질 수 있게 한다.

       (-3+5) 같은 경우는 따로 스코프를 복제해줄 필요가 없어서 괜찮다.

       그리고 -(7) 같이 스코프가 열리면 -를 쌓았다가 괄호가 끝날때 ')' 스코프의 영향을 제거해준다.

       처음에 부호를 ++ 로 미리 2개 쌓아둔 이유는 1+1 과 같이
       스코프용 + 와 부호 없이 등장하는 처음 숫자를 위한 + 를 넣어준 것이다.

    */
    int calculate(string s)
    {
        int total = 0;
        vector<int> signs(2, 1);                           // 현재 부호 저장 {+,+}
        s.erase(remove(s.begin(), s.end(), ' '), s.end()); // 문자열 공백 제거

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            if (isdigit(c))
            {
                int number = c - '0';
                while (i + 1 < s.size() && isdigit(s[i + 1]))
                {
                    number = 10 * number + (s[i + 1] - '0');

                    i++;
                }

                total += signs.back() * number; // - ( ) 현재 스코프에 해당하는 부호를 적용해서 total에 더함
                signs.pop_back();
            }
            else if (c == ')')
            {
                signs.pop_back();
            }
            else if (c == '(' && isdigit(s[i + 1]))
            {                                  // (3+5) 같은 경우
                signs.push_back(signs.back()); // 3을 계산하기 위한 기존 스코프 복제
            }
            else if (c == '(' && s[i + 1] == '-')
            {             // (-3+5) 같은 경우
                continue; // 복제할 필요 없음
            }
            else
            {
                signs.push_back(signs.back() * (c == '-' ? -1 : 1));
            }
        }
        return total;
    }
};