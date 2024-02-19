class Solution
{
public:
    vector<vector<bool>> visited;
    typedef pair<int, int> ci;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int spread(vector<vector<int>> &grid, int m, int n)
    {
        queue<ci> q;

        int fresh_orange_count = 0;

        // 전염 진원지 push
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                    visited[i][j] = true;
                }

                if (grid[i][j] == 1)
                {
                    fresh_orange_count++; // 개수를 미리 세어두면 굳이 O(n^2) 격자를 확인할 필요 X
                }
            }
        }

        int t = 0;
        while (!q.empty())
        {

            int size = q.size();

            cout << "t:" << t << "\n";

            for (int i = 0; i < size; i++)
            { // 단계별
                ci current = q.front();
                int r = current.first;
                int c = current.second;

                q.pop();

                for (int i = 0; i < 4; i++)
                {

                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc] || grid[nr][nc] != 1)
                    {
                        continue;
                    }

                    q.push({nr, nc});
                    visited[nr][nc] = true;
                    grid[nr][nc] = 2;
                    fresh_orange_count--; // 진원지는 제외하고 -를 하기 위해서
                }
            }
            t++;
        }

        if (fresh_orange_count > 0)
        { // 남아있으면
            return -1;
        }

        if (t <= 1)
        { // t=0 : rotten orange 가 하나도 없던 경우, t=1 : rotten 이 하나 있었는데 주변에 fresh 가 없던 경우
            return 0;
        }
        return t - 1; // 실제 완료는 q에 넣어서 끝난 타이밍인데, 거기서 q가 한번 더 도므로 -1 빼줌
    }

    int orangesRotting(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();

        visited.assign(m, vector<bool>(n, 0));

        return spread(grid, m, n);
    }
};