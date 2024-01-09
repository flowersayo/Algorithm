class Solution
{

    const int INF = 10001;

    // cheapest 뒤쪽으로 가장 큰 수 찾기
    // 만약 새롭게 cheapest 가 갱신되면 해당 cheapest 를 기준으로 재탐색(초기화)
public:
    int maxProfit(vector<int> &prices)
    {

        int ans = 0;
        int cheapest = prices[0];
        int highest = 0;
        for (int i = 1; i < prices.size(); i++)
        {

            if (cheapest > prices[i])
            { // 최솟값 갱신
                cheapest = prices[i];
                highest = 0;
                continue;
            }

            // 현재 최솟값 이후로 최댓값 갱신
            highest = max(highest, prices[i]);

            ans = max(ans, highest - cheapest);
        }

        return ans;
    }
    ver2.투포인터 풀이 int maxProfit(vector<int> &prices)
    {

        int left = 0, right = 1;

        // left -> buy stock ( 가장 작은 수 )
        // right -> sell stock ( left 다음 가장 큰 수 )

        int ans = 0;
        while (right < prices.size())
        {

            if (prices[left] < prices[right])
            {
                ans = max(ans, prices[right] - prices[left]);
            }
            else
            { // right 가 더 작은 상황 (포인터를 움직이다가 left보다 더 작은 수를 만남 )
                // left 가 현재 right 위치로 올때까지 움직인다. (left를 최솟값으로 갱신)

                left = right;
            }
            right++;
        }

        return ans;
    }
};