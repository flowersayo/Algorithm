/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    queue<string> split(const std::string &s, char delim)
    {
        queue<string> tokens;
        size_t start = 0, end = 0;
        while ((end = s.find(delim, start)) != string::npos)
        {
            tokens.push(s.substr(start, end - start));
            start = end + 1;
        }
        tokens.push(s.substr(start));
        return tokens;
    }
    string str = "";
    void preorder(TreeNode *root)
    {

        if (root == NULL)
        {
            str += " ,";
            return;
        }

        str += (to_string(root->val) + ",");

        preorder(root->left);
        preorder(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {

        preorder(root);

        cout << str << "\n";

        return str;
    }

    int cnt = 0; // data 에서 하나씩 꺼내오기 위함
    queue<string> tree_list;
    TreeNode *makeTree(string data)
    {

        if (tree_list.empty())
        { // 비어있다면
            return NULL;
        }

        string str = tree_list.front();
        tree_list.pop();
        if (str == " ")
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(stoi(str));

        root->left = makeTree(data);
        root->right = makeTree(data);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {

        tree_list = split(data, ',');
        return makeTree(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));