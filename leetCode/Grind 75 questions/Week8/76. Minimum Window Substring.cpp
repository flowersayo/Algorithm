class Solution
{
public:
    bool compare(int *t_alpha, int *alpha)
    {

        for (int i = 0; i < 128; i++)
        {
            if (t_alpha[i] > alpha[i])
            {
                return false;
            }
        }

        return true;
    }
    string minWindow(string s, string t)
    {

        string answer = "";
        int min_length = 100001;
        int left = 0, right = 0;
        int alpha[128] = {
            0,
        };
        int t_alpha[128] = {
            0,
        };

        for (int i = 0; i < t.size(); i++)
        {
            t_alpha[t[i]]++;
        }

        alpha[s[right]]++; // right에 해당하는 영역

        while (left < s.size() && right < s.size())
        {

            if (compare(t_alpha, alpha))
            { // 만약 일치하면 minimum window 구하기

                while (alpha[s[left]] > t_alpha[s[left]])
                { // left 포인터가 가리키는 문자를 빼도 되면

                    alpha[s[left]]--;
                    left++;
                }

                if (min_length > (right - left + 1))
                { // 최솟값 갱신
                    min_length = right - left + 1;
                    answer = s.substr(left, right - left + 1);
                }

                alpha[s[left]]--;
                left++;
            }
            else
            { // 일치할때까지 right 확장

                right++;
                alpha[s[right]]++;
            }
        }

        return answer;
    }

/*sol2*/
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;

        // counter : 현재 만족시킨 문자 갯수 
        // head : 최소 문자열의 시작점

        while(end<s.size()){
            if(map[s[end++]]-->0) counter--; // end가 가리키는 문자열이 t에 존재한다면 -> 하나 충족
            while(counter==0){ //valid한 문자열에 도달했다면
                if(end-begin<d)  d=end-(head=begin); // 최솟값 업데이트
                if(map[s[begin++]]++==0) counter++;  //make it invalid
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
    }