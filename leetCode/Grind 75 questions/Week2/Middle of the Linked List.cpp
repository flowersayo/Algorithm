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
    // 어떤 노드가 중앙인지 알려면 일단 끝까지 가서 전체 개수(n)를 알고, n/2번째 노드를 찾으면 된다.

    int totalSize(ListNode *head)
    {
        ListNode *current = head;

        int total_size = 0;

        while (current)
        {

            current = current->next;
            total_size++;
        }

        return total_size;
    }
    ListNode *middleNode(ListNode *head)
    {

        int total_size = totalSize(head);

        ListNode *current = head;

        int cnt = 0;
        for (int i = 0; i < total_size / 2; i++)
        {

            current = current->next;
            cnt++;
        }

        return current;
    }
};