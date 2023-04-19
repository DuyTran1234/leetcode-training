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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
        {
            return head;
        }
        while (head && head->val == val)
        {
            ListNode *remove = head;
            head = head->next ? head->next : nullptr;
            delete remove;
        }
        ListNode *current = head;
        while (current)
        {
            while (current->next && current->next->val == val)
            {
                ListNode *remove = current->next;
                current->next = remove->next ? remove->next : nullptr;
                delete remove;
            }
            current = current->next;
        }
        if (head && head->val == val && !head->next)
        {
            return nullptr;
        }
        return head;
    }
};