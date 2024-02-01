class TrieNode
{
public:
    TrieNode *child[26];
    bool isEnd;

    TrieNode()
    {
        isEnd = false;
        for (auto &c : child)
            c = nullptr;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        // root에서 내려가면서 word 의 한 글자씩 확인

        TrieNode *p = root;

        for (auto &c : word)
        {

            int idx = c - 'a';
            if (!p->child[idx])
            { // 존재하지 않으면
                p->child[idx] = new TrieNode();
            }
            p = p->child[idx];
        }

        p->isEnd = true; // 단어의 끝 표기
    }

    bool search(string word)
    {
        TrieNode *p = root;

        for (auto &c : word)
        { // 한 글자씩 내려가면서
            int idx = c - 'a';

            if (!p->child[idx])
            { // 존재하지 않으면

                return false;
            }

            p = p->child[idx];
        }

        return p->isEnd; // 단어의 끝인지 확인
    }

    bool startsWith(string prefix)
    {
        TrieNode *p = root;

        for (auto &c : prefix)
        { // 한 글자씩 내려가면서
            int idx = c - 'a';
            if (!p->child[idx])
            { // 존재하지 않으면
                return false;
            }
            p = p->child[idx];
        }

        return true; // 존재하지 않던 경우가 없으면
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */