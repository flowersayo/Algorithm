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
// 트리에서 노드 A의 높이 : A에서 가장 먼 리프 노드 까지 경로의 길이
// 왼쪽 서브트리의 높이 + 오른쪽 서브트리의 높이 = 해당 노드를 루트로 하는 서브트리의 지름
class Solution
{
public:
    int getHeight(TreeNode *root)
    {

        if (!root)
        {
            return 0;
        }

        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {

        if (!root)
        {
            return 0;
        }

        int diameter = getHeight(root->left) + getHeight(root->right);

        return max(diameter,

                   max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    // sol2. 각 노드에 대해 지름을 구하면서 최댓값 갱신
    int max_diameter = -1;

    int getHeight(TreeNode *root)
    {

        if (!root)
        {
            return 0;
        }

        int lheight = getHeight(root->left);
        int rheight = getHeight(root->right);

        max_diameter = max(max_diameter, lheight + rheight);

        return max(lheight, rheight) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {

        getHeight(root);

        return max_diameter;
    }
};