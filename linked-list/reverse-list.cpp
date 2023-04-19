

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
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *current = head;
        while (current->next)
        {
            ListNode *mem = current->next;
            current->next = mem->next;
            ListNode *memHead = head;
            head = mem;
            head->next = memHead;
        }
        return head;
    }
};