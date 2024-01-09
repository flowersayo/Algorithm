// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    { // 2^31 ~= 대략 21억 이분탐색 활용

        long long left = 1;
        long long right = n;

        long long mid;
        while (left <= right)
        { // true 이기 시작하는 lower bound 찾기

            mid = (left + right) / 2;

            if (isBadVersion(mid))
            {
                right = mid - 1; // bad 버전이 왼쪽에 더 있는지 탐색
            }
            else
            {
                left = mid + 1;
            }
        }

        return right + 1;
    }
};