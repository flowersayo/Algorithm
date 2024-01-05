class Solution
{
public:
    vector<vector<bool>> visited;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    typedef pair<int, int> ci;

    void bfs(vector<vector<int>> &image, int sr, int sc, int color)
    {

        queue<ci> q;
        int start_color = image[sr][sc];
        int r_size = image.size();
        int c_size = image[0].size();

        q.push({sr, sc});

        while (!q.empty())
        {

            ci current = q.front();

            int r = current.first;
            int c = current.second;
            visited[r][c] = true;
            image[r][c] = color;

            q.pop();

            for (int d = 0; d < 4; d++)
            {

                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= r_size || nr < 0 || nc >= c_size || nc < 0 || visited[nr][nc] || image[nr][nc] != start_color)
                {
                    continue;
                }

                q.push({nr, nc});
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        visited.assign(image.size(), vector<bool>(image[0].size(), false));

        bfs(image, sr, sc, color);

        return image;
    }
};