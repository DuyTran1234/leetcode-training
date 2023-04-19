
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int x)
    {
        this->val = x;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class MyLinkedList
{
public:
    Node *head;
    int size;
    MyLinkedList()
    {
        this->head = nullptr;
        this->size = 0;
    }

    int get(int index)
    {
        if (index >= size || index < 0)
        {
            return -1;
        }
        Node *current = head;
        for (int i = 0; i < index; ++i)
        {
            current = current->next;
        }
        return current->val;
    }

    void addAtHead(int val)
    {
        this->addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        this->addAtIndex(this->size, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index > this->size || index < 0)
        {
            return;
        }
        Node *newNode = new Node(val);
        if (index == 0)
        {
            if (!this->head)
            {
                this->head = newNode;
            }
            else
            {
                Node *mem = this->head;
                this->head = newNode;
                this->head->next = mem;
            }
        }
        else if (index == size)
        {
            for (Node *i = head; i != nullptr; i = i->next)
            {
                if (i->next == nullptr)
                {
                    i->next = newNode;
                    newNode->prev = i;
                    break;
                }
            }
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < index - 1; ++i)
            {
                current = current->next;
            }
            Node *mem = current->next;
            current->next = newNode;
            newNode->prev = current;
            newNode->next = mem;
            mem->prev = newNode;
        }
        ++this->size;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size || index < 0)
        {
            return;
        }
        if (index == 0)
        {
            if (this->head)
            {
                Node *mem = head;
                this->head = mem->next;
                delete mem;
            }
        }
        else if (index == size - 1)
        {
            for (Node *i = head; i != nullptr; i = i->next)
            {
                if (!i->next->next)
                {
                    Node *mem = i->next;
                    i->next = nullptr;
                    delete mem;
                    break;
                }
            }
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < index - 1; ++i)
            {
                current = current->next;
            }
            Node *remove = current->next;
            current->next = remove->next;
            remove->next->prev = current;
            delete remove;
        }
        --this->size;
    }
};
