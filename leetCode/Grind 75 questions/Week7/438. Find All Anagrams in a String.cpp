class Solution
{
public:
    bool compare(int *p_alpha, int *alpha)
    {

        for (int i = 0; i < 26; i++)
        {
            if (p_alpha[i] != alpha[i])
            {
                return false;
            }
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p)
    {

        // p 의 길이가 s 보다 긴 경우

        if (p.size() > s.size())
        {
            return {};
        }

        vector<int> answer;

        int p_alpha[26] = {
            0,
        }; // 크기가 고정된 경우 벡터 대신 정적 배열 사용

        for (int i = 0; i < p.size(); i++)
        {
            p_alpha[p[i] - 'a']++;
        }

        int alpha[26] = {
            0,
        };

        // 크기가 p.size 인 윈도우 크기 유지

        int left = 0, right = p.size() - 1;

        for (int i = 0; i < p.size(); i++)
        {
            alpha[s[i] - 'a']++;
        }

        if (compare(p_alpha, alpha))
        {
            answer.push_back(0);
        }

        while (true)
        {

            alpha[s[left] - 'a']--;
            left++;

            right++;

            if (right >= s.size())
            {
                break;
            }
            alpha[s[right] - 'a']++;

            if (compare(p_alpha, alpha))
            {
                answer.push_back(left);
            }
        }

        return answer;
    }
};