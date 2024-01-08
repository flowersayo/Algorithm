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
    // Node 를 거슬러 올라가면서 Parents 목록 반환
    vector<TreeNode *> find(TreeNode *root, int val)
    { // val을 지닌 노드의 부모목록 반환
        vector<TreeNode *> parents;
        TreeNode *current = root;

        do
        {

            parents.push_back(current);

            if (current->val < val)
            {
                current = current->right; // 오른쪽 탐색
            }
            else if (current->val > val)
            {
                current = current->left; // 왼쪽 탐색
            }
            else
            {
                break;
            }

        } while (true);

        return parents;
    }

    TreeNode *findFirstMatch(vector<TreeNode *> p_parents, vector<TreeNode *> q_parents)
    {

        unordered_map<int, bool> hash_map;

        for (TreeNode *p : p_parents)
        {

            hash_map[p->val] = true;
        }

        for (int i = q_parents.size() - 1; i >= 0; i--)
        {

            TreeNode *q = q_parents[i];

            if (hash_map.find(q->val) != hash_map.end())
            {
                return q;
            }
        }

        return NULL; // 같은 값 못 찾은 경우
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> p_parents = find(root, p->val);
        vector<TreeNode *> q_parents = find(root, q->val);

        return findFirstMatch(p_parents, q_parents);
    }
};