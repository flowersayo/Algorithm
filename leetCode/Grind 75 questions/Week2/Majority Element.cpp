class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        unordered_map<int, int> m;
        int size = nums.size();

        for (int i = 0; i < size; i++)
        {

            m[nums[i]]++; // 존재하지 않는 키에 접근하는 경우 해당 키에 대한 값을 0으로 초기화

            if (m[nums[i]] > size / 2)
            {
                return nums[i];
            }
        }

        return -1;
    }

    // sol2. Moore Voting Algorithm
    // * 내 스스로 증명 생각해보기 *
    // 1 1 1 1 1 1 1 ... 1이 majority이고 개수는 k개라 가정하면
    // 이 사이에 1이 아닌 원하는 숫자를 최대 k-1개 끼워 넣을 수 있다.
    // 그런데 어디에 어떤 숫자를 끼워넣든지, 결국은 1이 개수가 하나 더 많아서 1이 candidate 인 상황에서 끝나게 된다.
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int candidate = 0;

        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }

            if (num == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return candidate;
    }
};