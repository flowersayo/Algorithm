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
    // bfs 큐를 사용해 레벨(depth) 별로 노드를 담고, 그 중에서 가장 나중에 담아지는 노드를 right 노드로 치기

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> answer;

        queue<TreeNode *> q;

        if (!root)
        {
            return {};
        }
        TreeNode *current = root;

        q.push(current);

        while (!q.empty())
        {

            int size = q.size();

            for (int i = 0; i < size; i++)
            {

                TreeNode *current = q.front();
                q.pop();

                if (i == size - 1)
                {
                    answer.push_back(current->val);
                }

                if (current->left)
                {
                    q.push(current->left);
                }

                if (current->right)
                {
                    q.push(current->right);
                }
            }
        }

        return answer;
    }
};