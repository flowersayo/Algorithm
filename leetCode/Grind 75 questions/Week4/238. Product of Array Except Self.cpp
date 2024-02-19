class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int size = nums.size();
        vector<int> output(size, 1);

        int product = 1;
        for (int i = 0; i < size - 1; i++)
        {

            product *= nums[i];
            output[i + 1] *= product;
        }

        product = 1;
        for (int i = size - 1; i >= 1; i--)
        {

            product *= nums[i];
            output[i - 1] *= product;
        }

        return output;
    }
};