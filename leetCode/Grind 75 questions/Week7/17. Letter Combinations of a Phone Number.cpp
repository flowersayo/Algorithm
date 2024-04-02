class Solution
{
public:
    vector<string> answer;
    vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(int idx, string digits, string str)
    {

        if (idx == digits.size())
        {
            answer.push_back(str);
            return;
        }

        int num = digits[idx] - '0';

        for (int i = 0; i < pad[num].size(); i++)
        {

            char ch = pad[num][i];
            string new_str = str + ch;
            dfs(idx + 1, digits, new_str);
        }
    }
    vector<string> letterCombinations(string digits)
    {

        if (digits == "")
        { // 빈 문자열이라면
            return {};
        }

        dfs(0, digits, "");
        return answer;
    }
};