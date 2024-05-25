#define INF 987654321

class Solution {
public:
    map<string, bool> visited; // 최소 횟수 저장

    int bfs(string beginWord, unordered_set<string>& dict,
            string endWord) {
        queue<string> q;

        int ans = INF;

        q.push(beginWord);
        visited[beginWord] = true;

        int level = 1;

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                string word = q.front();
                q.pop();

                if (word == endWord) {
                   return level;
                }

                // find word which have excatly one letter different
                // word.length = m , dict.size = n 이라고 하면
                // m * 26 * O(logN)
                for (int i = 0; i < word.length(); i++) {

                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;

                        if (dict.find(word) != dict.end() &&
                            !visited[word]) {
                            visited[word] = true;
                            q.push(word);
                        }
                    }

                    word[i] = original;

                }
            }
            level++;
        }

        if (ans == INF) {
            return 0;
        }

        return ans;
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        return bfs(beginWord,dict,endWord);
    }
};