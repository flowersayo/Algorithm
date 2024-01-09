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

public:
    // Balanced Binary Tree : 두 서브트리의 높이(depth) 가 1 이상 차이나지 않는 것
    int getHeight(TreeNode *root)
    {

        if (!root)
        {
            return 0;
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        return 1 + max(leftHeight, rightHeight);
    }
    // 특정 root 가 balanced 일 조건 : 1. left 서브트리가 balance, 2. right 서브트리가 balance, 3. 현재 root 가 balance

    // ! left 와 right 가 모두 balance 라고 해서 root도 balance 라는 보장이 없음.
    bool isBalanced(TreeNode *root)
    {

        if (!root)
        {
            return true;
        }

        return abs(getHeight(root->left) - getHeight(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};