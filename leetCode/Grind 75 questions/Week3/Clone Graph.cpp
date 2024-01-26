/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {

        if (!node)
        {
            return NULL;
        }

        vector<Node *> _nodes(101, NULL); // 새로 클론한 정점 저장
        vector<int> sequence;
        queue<Node *> q;
        _nodes[node->val] = new Node(node->val);

        q.push(node);

        // 1. 모든 정점 생성하기

        while (!q.empty())
        {

            Node *current = q.front(); // 복제된 노드 지칭용
            q.pop();

            for (auto &neighbor : current->neighbors)
            {

                if (!_nodes[neighbor->val])
                { // 없는 정점이라면 (처음 방문하는 정점)
                    Node *new_node = new Node(neighbor->val);
                    _nodes[neighbor->val] = new_node;

                    q.push(neighbor);
                }

                _nodes[current->val]->neighbors.push_back(_nodes[neighbor->val]);
            }
        }

        return _nodes[node->val];
    }
};