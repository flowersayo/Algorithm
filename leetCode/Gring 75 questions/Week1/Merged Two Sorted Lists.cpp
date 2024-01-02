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

    typedef struct
    {
        ListNode *head;
        ListNode *tail;
        int length;
    } ListType;

    void init(ListType *list)
    {
        list->length = 0;
        list->head = list->tail = NULL;
    }

    void insert_last(ListType *list, ListNode *new_node)
    {

        if (list->head == NULL)
        {

            list->head = new_node;
            list->tail = new_node;
        }
        else
        {
            list->tail->next = new_node;
            list->tail = new_node;
        }
        list->length++;
    }

public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        ListType merged;
        init(&merged);

        while (list1 != NULL && list2 != NULL)
        {

            if (list1->val <= list2->val)
            {

                insert_last(&merged, list1);
                list1 = list1->next;
            }
            else
            {

                insert_last(&merged, list2);
                list2 = list2->next;
            }
        }

        while (list1 != NULL)
        {
            insert_last(&merged, list1);
            list1 = list1->next;
        }

        while (list2 != NULL)
        {
            insert_last(&merged, list2);
            list2 = list2->next;
        }

        return merged.head;
    }
};