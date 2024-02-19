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
    // left subtree 에 있는 노드들은 루트보다 작고, right subtree 에 있는 노드들은 루트보다 커야함
    // 내려가면서 루트가 만족해야하는 범위 지정하기 -> min < val < max
    // 최솟값은 min보다 커야함. 최댓값은 max 보다 작아야함.
    // 오른쪽으로 내려갈 때에는 max 에 대한 제한이 생기고,
    // 왼쪽으로 내려갈 때에는 min 에 대한 제한이 생긴다.

    bool isPossible(TreeNode *root, long long min, long long max)
    {

        if (!root)
        {
            return true;
        }

        bool isBetween = root->val > min && root->val < max;

        return isBetween && isPossible(root->left, min, root->val) && isPossible(root->right, root->val, max);
    }

    bool isValidBST(TreeNode *root)
    {

        return isPossible(root, LLONG_MIN, LLONG_MAX);
    }
};