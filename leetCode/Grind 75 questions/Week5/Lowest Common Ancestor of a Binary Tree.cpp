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
    // p 와 q 의 부모 목록을 각각 구해서
    // p의 부모 목록 : 1 3 5 7(p)
    // q의 부모 목록 : 1 3 6 9(q)
    // p와 q 의 가장 아랫 노드부터 거슬러 올라가면서 처음으로 같아지는 지점(LCA)을 반환한다.

    bool findRoute(TreeNode *root, TreeNode *p, vector<TreeNode *> &parents)
    { // p ~ root 까지의 부모 목록들을 반환.

        if (!root)
        {
            return false;
        }

        parents.push_back(root);

        if (root == p)
        { // 원하는 노드를 찾으면 여기까지의 경로를 저장한다.
            return true;
        }

        if (findRoute(root->left, p, parents) || findRoute(root->right, p, parents))
        { // 현재 root 의 왼 or 오 에서 원하는 노드를 찾았다면
            return true;
        }

        parents.pop_back(); // 만약에 하위에서 원하는 노드를 찾지 못했으면
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> p_parents;
        vector<TreeNode *> q_parents;

        findRoute(root, p, p_parents);
        findRoute(root, q, q_parents);

        for (int i = q_parents.size() - 1; i >= 0; i--)
        {

            if (find(p_parents.begin(), p_parents.end(), q_parents[i]) != p_parents.end())
            {
                return q_parents[i];
            }
        }

        return NULL;
    }
};