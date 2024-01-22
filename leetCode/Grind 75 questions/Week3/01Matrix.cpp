class Solution
{
public:
    typedef pair<int, int> ci;

    // 북 동 남 서
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void bfs(queue<ci> &q, int sr, int sc, vector<vector<int>> &mat, int m, int n, vector<vector<int>> &min_dist)
    {

        // 0부터 나머지 정점들까지의 최단거리 업데이트
        // 여러개의 0들을 먼저 큐에 넣으면 여러개의 0에서 동시에(병렬적으로) 탐색하는 것과 같은 효과를 줄 수 있음.

        while (!q.empty())
        {

            ci current = q.front();

            int r = current.first;
            int c = current.second;

            q.pop();

            for (int d = 0; d < 4; d++)
            {

                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || min_dist[nr][nc] || mat[nr][nc] == 0)
                {
                    // 0쪽으로는 어짜피 최단거리가 아니기에 탐색할 필요가 없다.
                    // 이미 최단거리가 먼저 업데이트 되어있다면 더 업데이트 할 필요가 없다.
                    continue;
                }

                q.push({nr, nc});
                min_dist[nr][nc] = min_dist[r][c] + 1; // 최단거리 갱신 (항상 최솟값임을 보장)
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> min_dist(m, vector<int>(n, 0));
        queue<ci> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (mat[i][j] == 0)
                {
                    q.push({i, j}); // 0 위치 좌표 넣기
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (mat[i][j] == 0)
                {
                    bfs(q, i, j, mat, m, n, min_dist);
                }
            }
        }

        return min_dist;
    }
};