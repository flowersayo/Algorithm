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
    // sol1: 내풀이
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        vector<vector<int>> answer;

        if (!root)
        {
            return answer;
        }

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        int current_depth = 0;
        vector<int> current_level;

        while (!q.empty())
        {

            pair<TreeNode *, int> Ti = q.front();
            TreeNode *current = Ti.first;
            int depth = Ti.second;

            q.pop();

            if (!current)
            {
                continue;
            }

            q.push({current->left, depth + 1});
            q.push({current->right, depth + 1});

            if (current_depth == depth)
            {
                current_level.push_back(current->val);
            }
            else
            {
                current_depth++;
                answer.push_back(current_level);
                current_level.clear();
                current_level.push_back(current->val);
            }
        }
        answer.push_back(current_level);

        return answer;
    }

    // sol2

    vector<vector<int>> levelOrder(TreeNode *root)
    {

        vector<vector<int>> answer;

        if (!root)
        {
            return answer;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {

            int s = q.size(); // 1, 2, 4, 8
            // 한 레벨을 지날 수록 자식 노드의 수는 2^n 만큼 생긴다.
            // 이전 레벨의 노드를 다 꺼내주고 나면 남은 것이 그 다음레벨의 노드가 된다.
            vector<int> temp;
            for (int i = 0; i < s; i++)
            {
                TreeNode *current = q.front();
                temp.push_back(current->val);
                q.pop();

                if (current->left)
                {
                    q.push(current->left);
                }

                if (current->right)
                {
                    q.push(current->right);
                }
            }
            answer.push_back(temp);
        }

        return answer;
    }
};