/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    // sol1 . 방문한 노드 목록을 map 에 저장해두기

    bool hasCycle(ListNode *head)
    {

        ListNode *current = head;

        map<ListNode *, bool> m; // head 로부터 얼마만큼 멀리 떨어져 있는지.

        while (current)
        {

            cout << current->val << " ";
            if (m[current])
            { // 방문한 적이 있다면
                return true;
            }

            m[current] = true;

            current = current->next;
        }

        return false;
    }

    // sol2. Floyd’s Cycle-Finding Algorithm
    // 시간 복잡도 : O(N)
    // Q. fast 포인터가 slow 포인터를 항상 추월할 수 있지 않은가? (=두 포인터가 만나는 일이 없을수도 있지 않는가)
    // A. 매 반복마다 fast 포인터 ~ slow 포인터 사이 거리(gap)가 1씩 줄어들기 때문에 언젠간 gap=0 이 되는 날이 반드시 온다. 다만 만일 fast 가 3칸씩 이동한다면 반드시 만난다는 보장이 없다.

    bool hasCycle(ListNode *head)
    {

        ListNode *fast = head;
        ListNode *slow = head;

        while (!fast == NULL && fast->next != NULL)
        {

            fast = fast->next->next;
            slow = slow->next;

            // 어떤 지점에서 left 와 right가 만나면
            if (fast == slow)
            {
                return true;
            }
        }

        return false;
    }
};