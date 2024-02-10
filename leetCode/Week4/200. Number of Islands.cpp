class Solution
{
public:
    vector<vector<bool>> visited;
    typedef pair<int, int> ci;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void bfs(int sr, int sc, vector<vector<char>> &grid, int m, int n)
    {

        queue<ci> q;

        q.push({sr, sc});
        visited[sr][sc] = true;

        while (!q.empty())
        {

            ci current = q.front();
            int r = current.first;
            int c = current.second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc] || grid[nr][nc] != '1')
                {
                    continue;
                }

                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {

        int answer = 0;

        int m = grid.size();
        int n = grid[0].size();

        visited.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                { // 1인 영역만 탐색

                    bfs(i, j, grid, m, n);
                    answer++;
                }
            }
        }

        return answer;
    }
};