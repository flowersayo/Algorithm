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
    int answer = 0;
    int cnt = 0;
    // k 번째 중위순회 결과

    int inorder_iterative(TreeNode *root, int k)
    {

        stack<TreeNode *> st;
        int cnt = 0;

        // root 의 왼쪽에 있는 꼭대기 노드들 모두 삽입
        while (root != NULL)
        {
            st.push(root);
            root = root->left;
        }

        while (cnt != k)
        {
            TreeNode *root = st.top();
            st.pop();
            cnt++;

            if (k == cnt)
            {
                return root->val;
            }

            TreeNode *right = root->right;
            // right 의 왼쪽 끝 노드 탐색
            while (right != NULL)
            {
                st.push(right);
                right = right->left;
            }
        }

        return -1;
    }
    void inorder(TreeNode *root, int k)
    { // left -> root -> right

        if (root == NULL)
        {
            return;
        }

        inorder(root->left, k);
        cnt++;
        if (cnt == k)
        {
            answer = root->val;
        }

        inorder(root->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {

        // inorder(root,k);

        return inorder_iterative(root, k);
    }
};