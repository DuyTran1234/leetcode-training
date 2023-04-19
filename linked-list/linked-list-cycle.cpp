

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
        {
            return false;
        }
        if (!head->next)
        {
            return false;
        }
        if (!head->next->next)
        {
            return false;
        }
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;

        while (fast && fast->next)
        {
            if (slow == fast)
            {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};