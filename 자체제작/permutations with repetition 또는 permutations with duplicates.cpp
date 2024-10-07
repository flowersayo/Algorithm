#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

// 1. balance 2. depth = 3 이하인지 체크
bool checkParentheses(const string &s)
{
    stack<char> stack;

    int cnt = 0; // 현재 깊이 검사.
    unordered_map<char, char> parentheses = {
        {')', '('},
        {']', '['}};

    for (char c : s)
    {

        if (c == '(' || c == '[')
        { // 여는 괄호일 경우
            stack.push(c);

            if (stack.size() >= 4)
            { // 스택에 남아있는 열린 괄호가 4개 이상(depth>=4)
                return false;
            }
        }
        else if (c == ')' || c == ']')
        {
            if (stack.empty() || stack.top() != parentheses[c])
            {
                return false;
            }
            stack.pop(); // 짝이 맞으면 스택에서 제거
        }
    }

    return stack.empty(); // 스택이 비어 있으면 모든 짝이 맞음
}

string parentheses_list = "(((())))[[]]";
vector<bool> visited(12, false);
int answer = 0;

// 모든 가능한 괄호 조합 구하기
void dfs(int idx, string str)
{

    if (idx == 12 && checkParentheses(str))
    {
        cout << str << "\n";
        answer++;
        return;
    }

    char last = '-';
    for (int i = 0; i < parentheses_list.length(); i++)
    {

        if (visited[i])
        {
            continue;
        }
        // 같은 것이 있는 순열을 프로그래밍적으로 어떻게 구현하기?
        // 이전 선택과중복되는 선택지는 제외
        if (last == parentheses_list[i])
        {
            continue;
        }

        visited[i] = true;
        last = parentheses_list[i];

        dfs(idx + 1, str + parentheses_list[i]);

        visited[i] = false;
    }
}

int main()
{

    dfs(0, "");

    cout << answer;

    return 0;
}