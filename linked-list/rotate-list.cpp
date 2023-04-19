
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next)
        {
            return head;
        }
        int size = 0;
        for (ListNode *i = head; i != nullptr; i = i->next)
        {
            ++size;
        }
        k = k % size;

        ListNode *slow = head;
        ListNode *fast = head;
        for (int i = 0; i < k; ++i)
        {
            fast = fast->next;
        }
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *mem = slow->next;
        slow->next = nullptr;
        fast->next = head;
        head = mem;
        return head;
    }
};