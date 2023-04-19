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
    bool isPalindrome(ListNode *head)
    {
        if (!head->next)
        {
            return true;
        }
        if (!head->next->next)
        {
            return head->val == head->next->val;
        }
        ListNode *haft = this->endOfHalf(head);
        ListNode *cursor = haft;

        while (cursor->next)
        {
            ListNode *mem = cursor->next;
            cursor->next = mem->next;
            ListNode *memHaft = haft;
            haft = mem;
            haft->next = memHaft;
        }
        ListNode *list1 = head;
        ListNode *list2 = haft;
        while (list1 != haft && list2 != nullptr)
        {
            if (list1->val != list2->val)
            {
                return false;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
        return true;
    }

    ListNode *endOfHalf(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next->next;
        while (fast)
        {
            fast = fast->next ? fast->next->next : nullptr;
            slow = slow->next;
            if (!fast)
            {
                break;
            }
        }
        return slow;
    }
};