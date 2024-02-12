#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef pair<char, int> ci;

int countCloseBeforeIdx(int end_idx, string str)
{

    int cnt = 0;
    for (int i = end_idx; i >= 0; i--)
    {
        if (str[i] == ')')
        {
            cnt++;
        }
    }

    return cnt;
}
int countOpenAfetIdx(int start_idx, string str)
{

    int cnt = 0;
    for (int i = start_idx; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            cnt++;
        }
    }

    return cnt;
}
// )) 가 두개이상 쌓이면 이후 어떤 입력값이 주어져도 못할거라고 판단 가능
int isRightparenthesis(string str)
{

    stack<ci> st;

    int unmatched_cnt = 0; // 짝이 없는 괄호

    for (int i = 0; i < str.size(); i++)
    {

        char c = str[i];

        if (c == '(')
        {
            st.push({c, i});
        }
        else if (c == ')')
        {
            if (st.empty())
            {
                return countCloseBeforeIdx(i, str);
            }

            if (st.top().first == '(')
            {
                st.pop();
            }
        }
    }
    return countOpenAfetIdx(st.top().second, str);
}

/**
 * [백준 24552] 올바른 괄호열
 * https://www.acmicpc.net/problem/24552
 *
 * 정확히 하나의 괄호를 지워 올바른 괄호열을 만들 수 있는 경우의 수를 구하는 문제
 * 괄호 짝을 모두 맞추고 나면 결국 스택에는 '(' 또는 ')' 가 단 하나 남는다.
 * 스택에 남아있는 괄호의 짝을 맞추기 위해서는 하나의 괄호를 지움으로서 짝이 안맞는 괄호를 하나 만들어서 기존에 있던 괄호와 짝을 맞추어 pop시켜주면 된다.
 *
 * 1) '(' 가 남아있을 경우 그 '(' 이후의 '(' 개수가 정답이 된다. 이후의 '(' 를 하나 지우면 짝이 안맞는 ')'가 하나 생기게 되고 기존에 있던 '(' 와 짝을 이룰 수 있게 된다.
 *      => 기존 '(' + 삭제 후 짝을 잃은 ')' 가 함께 pop
 * 2) ')' 가 남아있을 경우 그 ')' 이전의 ')' 개수가 정답이 된다. 이전의 ')' 를 하나 지우면 짝이 안맞는 '('가 하나 생기게 되고 기존에 있던 ')' 와 짝을 이룰 수 있게 된다.
 *      => 삭제 후 짝을 잃은 '(' + 기존 ')' 가 함께 pop
 *
 */
int main()
{

    string str;

    cin >> str;

    cout << isRightparenthesis(str);
}