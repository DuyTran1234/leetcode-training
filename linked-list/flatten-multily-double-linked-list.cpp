class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (!head)
        {
            return head;
        }
        Node *current = head;
        while (current)
        {
            if (current->child)
            {
                Node *p = current->child;
                Node *mem = current->next;
                current->next = current->child;
                current->child->prev = current;
                current->child = nullptr;
                while (p->next)
                {
                    p = p->next;
                }
                p->next = mem;
                if (mem)
                {
                    mem->prev = p;
                }
            }
            current = current->next;
        }
        return head;
    }
};