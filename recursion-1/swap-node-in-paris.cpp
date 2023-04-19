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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        ListNode *cur = nullptr;
        head = fast;

        while (slow && fast)
        {
            slow->next = fast->next;
            fast->next = slow;
            ListNode *mem = slow;
            slow = fast;
            fast = mem;
            if (cur)
            {
                cur->next = slow;
            }
            cur = fast;
            slow = slow->next ? slow->next->next : nullptr;
            fast = fast->next ? fast->next->next : nullptr;
            if (!slow || !fast)
            {
                break;
            }
        }
        return head;
    }
};