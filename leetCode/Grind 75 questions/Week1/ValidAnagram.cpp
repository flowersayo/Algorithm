class Solution
{
public:
    vector<int> alphaMap(string str)
    {
        vector<int> alpha(26, 0);

        for (char c : str)
        {
            alpha[c - 'a'] += 1;
        }

        return alpha;
    }

    bool compare(vector<int> alpha1, vector<int> alpha2)
    {

        for (int i = 0; i < 26; i++)
        {
            if (alpha1[i] != alpha2[i])
            {
                return false;
            }
        }

        return true;
    }
    bool isAnagram(string s, string t)
    {

        vector<int> s_alpha = alphaMap(s);
        vector<int> t_alpha = alphaMap(t);

        return compare(s_alpha, t_alpha);
    }
};