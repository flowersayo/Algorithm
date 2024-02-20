class Solution
{
public:
    vector<vector<int>> answer;
    vector<bool> visited;

    void permutation(vector<int> &nums, int n, vector<int> arr)
    {

        if (arr.size() == n)
        {
            answer.push_back(arr);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i])
            {
                continue;
            }

            visited[i] = true;
            arr.push_back(nums[i]);
            permutation(nums, n, arr);
            visited[i] = false;
            arr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        visited.assign(nums.size(), false);
        permutation(nums, nums.size(), {});

        return answer;
    }
};