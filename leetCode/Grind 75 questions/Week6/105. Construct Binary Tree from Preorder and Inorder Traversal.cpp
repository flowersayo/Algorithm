/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    unordered_map<int, int> inorder_idx; // {값:인덱스}
    // idx: 전위 순회에서 인덱스, start : 서브트리의 왼쪽 경계(중위 순회), end : 서브트리의 오른쪽 경계(중위 순회)
    TreeNode *makeTree(int idx_in_preorder, int start, int end,
                       vector<int> &preorder, vector<int> &inorder, int n)
    {

        if (start > end)
        {
            return NULL;
        }

        int val = preorder[idx_in_preorder];
        int idx_in_inorder = inorder_idx[val]; // 중위 순회에서의 인덱스

        int size_of_left_subtree = idx_in_inorder - start;

        // 오른쪽 서브트리의 루트 인덱스 = 루트 인덱스 + 왼쪽 서브트리
        // 크기(idx_in_inorder-start) + 1
        int root_idx_of_right_subtree =
            idx_in_preorder + size_of_left_subtree + 1;
        int left_val = preorder[idx_in_preorder + 1];

        TreeNode *root = new TreeNode(val);

        // 1. 왼쪽 서브트리

        root->left = makeTree(idx_in_preorder + 1, start,
                              idx_in_inorder - 1, preorder, inorder, n);

        // 2. 오른쪽 서브트리

        int right_val = preorder[idx_in_preorder + 1];

        root->right = makeTree(root_idx_of_right_subtree,
                               idx_in_inorder + 1, end, preorder, inorder, n);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        TreeNode *root = new TreeNode(preorder[0]);

        int n = preorder.size();

        for (int i = 0; i < inorder.size(); i++)
        {
            inorder_idx[inorder[i]] = i;
        }

        return makeTree(0, 0, n - 1, preorder, inorder, n);
    }
};