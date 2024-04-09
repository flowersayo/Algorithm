class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {

        int counter[26] = {
            0,
        };

        int max = 0;
        int maxCount = 0;

        for (auto task : tasks)
        {
            counter[task - 'A']++;

            if (max == counter[task - 'A'])
            {
                maxCount++;
            }
            else if (max < counter[task - 'A'])
            {
                max = counter[task - 'A'];
                maxCount = 1;
            }
        }

        int partCount = max - 1;             // 파트의 개수
        int partLength = n + 1 - (maxCount); // 전체 n + 1 중 maxCount 만큼 이미 차있음
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - max * maxCount; // 사용 가능한 task 개수

        // most frequency 순으로 그룹에 배치한다고 가정.
        // 만약 종류 > 그룹 크기라면 유연하게 그룹 크기를 늘려서 배치하면 된다.
        int idles = std::max(0, emptySlots - availableTasks);

        return tasks.size() + idles;
    }
};