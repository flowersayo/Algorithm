class Solution
{
public:
    vector<vector<int>> answer;

    void combination(vector<int> &candidates, int target, vector<int> arr, int sum, int start)
    {

        if (target <= sum)
        {

            if (target == sum)
            {
                answer.push_back(arr);
            }

            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {

            arr.push_back(candidates[i]);
            combination(candidates, target, arr, sum + candidates[i], i);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        combination(candidates, target, {}, 0, 0);

        return answer;
    }
};