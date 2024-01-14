class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> us; // 키-값을 매칭할 필요 없이 존재 여부마나 필요하므로 set 사용

        for (int i = 0; i < nums.size(); i++)
        {

            if (us.find(nums[i]) != us.end())
            {
                return true;
            }

            us.insert(nums[i]);
        }

        return false;
    }
};