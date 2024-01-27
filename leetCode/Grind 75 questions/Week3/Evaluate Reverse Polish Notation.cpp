class Solution
{
public:
    int calc(int a, int b, char sign)
    {

        switch (sign)
        {

        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            return a / b;
        }

        return -1;
    }

    int evalRPN(vector<string> &tokens)
    {

        stack<int> nums;

        for (auto &token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                if (nums.size() >= 2)
                {
                    int operand2 = nums.top();
                    nums.pop();
                    int operand1 = nums.top();
                    nums.pop();
                    char sign = token[0];

                    nums.push(calc(operand1, operand2, sign));
                    cout << operand1 << sign << operand2 << "\n";
                }
            }
            else
            {
                nums.push(stoi(token));
            }
        }

        return nums.top();
    }
};