

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        if (!head->next)
        {
            return nullptr;
        }
        if (!head->next->next)
        {
            return nullptr;
        }
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        ListNode *entry = head;
        while (fast && fast->next)
        {
            if (slow == fast)
            {
                while (slow != entry)
                {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return nullptr;
    }
};