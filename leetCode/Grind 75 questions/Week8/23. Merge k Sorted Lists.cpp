/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    /*
    기본적인 아이디어 : 리스트의 모든 노드들을 우선순위 큐에 넣고 O(log N) 작은 순서대로
    pop한다.

    가장 간단하지만, 각 리스트가 이미 정렬된 상태라는 장점을 활용하지 못한다.

    각 리스트가 이미 정렬된 상태라는 점을 활용하여 조금 더 최적화 할 수 있다.
    분할 정복에서 두개의 리스트를 합병하는 것처럼, 리스트의 처음 원소들을 차례대로 비교해가면서 값이 작은 값을 결과리스트에 넣는다.
    우선 순위 큐의 크기가 최대 k까지로 제한되므로 시간복잡도가 줄어든다.

    총 시간 복잡도 : O(klogk) +  O(nlogk)  = O((k+n)logk)

    - 처음 k개의 원소를 넣는데에 O(klogk)
    - 이후 나머지 원소를 넣는데에 O(nlogk)
    - 이후 나머지 원소를 팝하는데에 O(nlogk)

    이때 n은 리스트의 원소 총 개수를 의미.


    */

    struct cmp
    {
        bool operator()(const ListNode *node1, const ListNode *node2) const
        {
            return node1->val > node2->val; // min_heap
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

        for (auto l : lists)
        { // 각 리스트의 첫번째 노드 삽입

            if (l)
            {
                pq.push(l);
            }
        }

        if (pq.empty())
        { // pq 가 비어있는 경우
            return NULL;
        }

        ListNode *head = pq.top();
        pq.pop();

        if (head->next)
        {
            pq.push(head->next);
        }

        ListNode *tail = head; // 현재 가리키고 있는 마지막 노드

        while (!pq.empty())
        {

            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            if (tail->next)
                pq.push(tail->next);
        }

        return head;
    }
};
