class Solution
{
public:
    int trap(vector<int> &height)
    {

        int n = height.size();
        int left = 0;
        int right = n - 1; // 양끝에서 서로 가까워지는 포인터
        int ans = 0;
        int max_left = 0, max_right = 0; // 양끝에서 가장 높은 벽

        while (left <= right)
        {
            if (height[left] <= height[right])
            {

                if (height[left] >= max_left)
                { // max_left 최댓값 갱신
                    max_left = height[left];
                }
                else
                { // 이전 벽보다 낮은 블럭(웅덩이) 이면 바로 물을 채운다.
                    ans += max_left - height[left];
                }
                left++;
            }
            else
            {

                if (height[right] >= max_right)
                { // max_left 최댓값 갱신
                    max_right = height[right];
                }
                else
                { // 이전 벽보다 낮은 블럭(웅덩이) 이면 바로 물을 채운다.
                    ans += max_right - height[right];
                }
                right--;
            }
        }

        return ans;
    }
};