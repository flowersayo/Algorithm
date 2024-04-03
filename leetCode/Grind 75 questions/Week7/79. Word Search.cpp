class Solution
{
public:
    bool answer = false;

    // 상 하 좌 우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    vector<vector<bool>> visited;

    void dfs(int idx, int r, int c, string target, string str, int n, int m, vector<vector<char>> &board)
    {

        if (target[idx - 1] != str[idx - 1])
        {
            return;
        }

        if (idx == target.size())
        {
            if (target == str)
            {
                answer = true;
            }

            return;
        }

        for (int i = 0; i < 4; i++)
        {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc])
            {
                continue;
            }

            visited[nr][nc] = true;

            string new_str = str + board[nr][nc];

            dfs(idx + 1, nr, nc, target, new_str, n, m, board);

            visited[nr][nc] = false;
        }
    }

    bool exist(vector<vector<char>> &board, string word)
    {

        int n = board.size();
        int m = board[0].size();

        visited.assign(n, vector<bool>(m, false));

        map<char, int> alpha;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                alpha[board[i][j]]++;
            }
        }

        map<int, int> word_count;

        for (int i = 0; i < word.size(); i++)
        {
            word_count[word[i]]++;
        }

        for (auto iter : word_count)
        {
            if (alpha[iter.first] < iter.second)
            { // 애초에 개수가 모자라다면
                return false;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {

                    visited[i][j] = true;
                    dfs(1, i, j, word, string(1, word[0]), n, m, board);
                    visited[i][j] = false;
                }
            }
        }

        return answer;
    }
};