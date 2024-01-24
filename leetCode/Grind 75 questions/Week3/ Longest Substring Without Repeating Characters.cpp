class Solution
{
public:
    // sol1 : 내풀이
    // 623ms 143.9 MB
    int lengthOfLongestSubstring(string s)
    {

        unordered_map<char, int> ump;

        int max_length = 0;
        int combo = 0;

        for (int i = 0; i < s.size(); i++)
        {

            if (ump.find(s[i]) != ump.end())
            { // 중복되는 값을 찾으면

                // 방문 기록 및 콤보 초기화
                int next = i - 1;
                int dist = 0;

                // 방문 기록 조정
                ump.clear();
                ump[s[i]] = 1;

                // 뒤로 돌아가기
                while (s[next] != s[i])
                {
                    ump[s[next]] = 1; // 이전에 나온 알파벳만 추가
                    next--;
                    dist++;
                }

                combo = dist + 1;
                max_length = max(max_length, combo);

                continue;
            }

            combo++;
            ump[s[i]]++;
            max_length = max(combo, max_length);
        }

        return max_length;
    }

    // sol2: 마지막 문자가 나온 곳을 기억해두면 굳이 중복된 문자가 나타나기 이전까지 직접 반복을 돌지 않고도 O(1)만에 알 수 있음.
    // 76 ms 11.3MB
    int lengthOfLongestSubstring(string s)
    {

        unordered_map<char, int> ump;

        int max_length = 0;
        int combo = 0;

        int start = 0, end = 0; // start ~ end 슬라이딩 윈도우

        for (int i = 0; i < s.size(); i++)
        {

            if (ump.find(s[i]) != ump.end())
            { // 중복되는 값을 찾으면

                if (ump[s[i]] >= start)
                { // 마지막 중복 문자 다음 으로 시작점 옮기기

                    start = ump[s[i]] + 1;
                }

                ump[s[i]] = i;
                end = i;

                max_length = max(end - start + 1, max_length);

                continue;
            }

            end = i;
            ump[s[i]] = i; // 마지막으로 나온 곳 저장.
            max_length = max(end - start + 1, max_length);
        }

        return max_length;
    }
};