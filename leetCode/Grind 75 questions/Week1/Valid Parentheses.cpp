#include <stack>
#include <map>

class Solution
{
public:
    bool isValid(string s)
    {

        stack<int> st;
        map<char, char> brackets;

        brackets[')'] = '(';
        brackets[']'] = '[';
        brackets['}'] = '{';

        st.push(s[0]);

        for (int i = 1; i < s.length(); i++)
        {

            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            { // if()
                st.push(s[i]);
                continue;
            }

            if (!st.empty() && st.top() == brackets[s[i]])
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }

        return st.empty();
    }
};