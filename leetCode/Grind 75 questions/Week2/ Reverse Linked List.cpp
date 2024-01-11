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
    ListNode *reverseList(ListNode *head)
    {

        ListNode *before = NULL;
        ListNode *current = head;

        // before : null, current : head 로 잡으면 첫번째 노드의 연결을 null로 해주는 코드를 따로 작성할 필요가 없다.

        while (current)
        {

            ListNode *after = current->next; // 진짜 next 킵
            current->next = before;

            before = current;
            current = after;
        }

        return before;
    }
};