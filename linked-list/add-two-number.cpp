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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
        {
            return nullptr;
        }
        if (!l1)
        {
            return l2;
        }
        if (!l2)
        {
            return l1;
        }
        ListNode *head = l1;
        ListNode *tail = l1;
        bool mem = false;

        while (l1 && l2)
        {
            int rs = mem + l1->val + l2->val;
            mem = rs >= 10 ? true : false;
            l1->val = rs % 10;
            if (!l1->next)
            {
                tail = l1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            int rs = mem + l1->val;
            mem = rs >= 10 ? true : false;
            l1->val = rs % 10;
            if (!l1->next)
            {
                tail = l1;
            }
            l1 = l1->next;
        }
        while (l2)
        {
            int rs = mem + l2->val;
            mem = rs >= 10 ? true : false;
            ListNode *newNode = new ListNode(rs % 10);
            tail->next = newNode;
            tail = newNode;
            l2 = l2->next;
        }
        if (mem)
        {
            ListNode *newNode = new ListNode(1);
            tail->next = newNode;
        }
        return head;
    }
};