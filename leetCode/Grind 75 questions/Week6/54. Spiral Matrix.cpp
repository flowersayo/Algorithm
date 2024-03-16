class Solution
{
public:
    // 동 북 서 남

    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {1, 0, -1, 0};

    // 경계를 따라 안쪽으로 이동하면 된다.
    // 각 방향으로 이동하고 나면 그쪽 방향의 바운더리가 -1 씩 줄어든다.
    // start, end of boundary 를 기억하자.

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> answer;

        // 이동할 수 있는 boundary

        int start_r = 0;
        int start_c = 0;
        int end_r = n - 1;
        int end_c = m - 1;

        // 이동할 칸이 있을때에만
        while (start_r <= end_r && start_c <= end_c)
        {

            // 동
            for (int j = start_c; j <= end_c && answer.size() < n * m; j++)
            {
                answer.push_back(matrix[start_r][j]);
            }
            // answer.size()<n*m : 특정 방향으로 이동하고 나서 더이상 이동할 곳이 없는지 확인하기 위함.
            // 격자판의 전체 개수가 n*m 이고 따라서 이미 n*m 개의 원소를 모두 방문했다면 더이상 이동할 곳이 없음

            start_r++;

            // 북

            for (int i = start_r; i <= end_r && answer.size() < n * m; i++)
            {
                answer.push_back(matrix[i][end_c]);
            }

            end_c--;

            // 서

            for (int j = end_c; j >= start_c && answer.size() < n * m; j--)
            {
                answer.push_back(matrix[end_r][j]);
            }
            end_r--;

            // 남

            for (int i = end_r; i >= start_r && answer.size() < n * m; i--)
            {
                answer.push_back(matrix[i][start_c]);
            }

            start_c++;
        }

        return answer;
    }
};