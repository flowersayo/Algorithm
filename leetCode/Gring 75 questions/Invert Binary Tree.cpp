/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public: // root 기준 왼쪽 <-> 오른쪽 재귀적
    TreeNode *invertTree(TreeNode *root)
    {

        // root -> left 와 root -> right 를 바꾼다.
        if (root == nullptr)
        {
            return root;
        }
        TreeNode *left = root->left;
        root->left = root->right; // 교환
        root->right = left;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};