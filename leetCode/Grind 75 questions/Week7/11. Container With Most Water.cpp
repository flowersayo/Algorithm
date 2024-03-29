class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        int left = 0;
        int right = height.size() - 1;
        int answer = -1;

        // 높은 기둥 하나는 고정해두고 낮은 기둥을 이동
        while (left < right)
        {

            int area_size = (right - left) * min(height[left], height[right]); // 가로 x 세로

            answer = max(answer, area_size);

            if (height[left] < height[right])
            {
                left++;
            }
            else if (height[left] > height[right])
            {
                right--;
            }
            else
            {
                left++;
                right--;
            }
        }

        return answer;
    }
};