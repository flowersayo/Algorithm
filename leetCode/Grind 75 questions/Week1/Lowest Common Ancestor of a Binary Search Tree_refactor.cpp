/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    // p <= root <= q 를 만족하는 지점이 바로 LCA 이다.
    // 왜냐하면 root 를 기준으로 왼쪽에 있는 모든 노드들은 오른쪽 노드보다 작기 때문이다.

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (!root)
        {
            return root;
        }

        if (p->val <= root->val && root->val <= q->val)
        {
            return root;
        }
        else if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};