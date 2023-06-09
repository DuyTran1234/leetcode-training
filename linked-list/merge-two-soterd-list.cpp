#include <algorithm>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1 && !list2)
        {
            return nullptr;
        }
        if (!list1)
        {
            return list2;
        }
        if (!list2)
        {
            return list1;
        }
        if (list1->val > list2->val)
        {
            std::swap(list1, list2);
        }
        ListNode *head = list1;
        while (list1->next && list2)
        {
            if (list1->next->val > list2->val)
            {
                ListNode *mem = list1->next;
                list1->next = list2;
                list2 = list2->next;
                list1->next->next = mem;
            }
            list1 = list1->next;
        }

        if (list2)
        {
            list1->next = list2;
        }

        return head;
    }
};