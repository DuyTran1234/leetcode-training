
class Node
{
public:
    int val;
    Node *next;
    Node(int x)
    {
        this->val = x;
        this->next = nullptr;
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
        if (index >= this->size || index < 0)
        {
            return -1;
        }
        Node *current = this->head;
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
        if (index > size || index < 0)
        {
            return;
        }
        Node *newNode = new Node(val);
        if (index == 0)
        {
            if (this->head == nullptr)
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
        else if (index == this->size)
        {
            for (Node *i = this->head; i != nullptr; i = i->next)
            {
                if (!i->next)
                {
                    i->next = newNode;
                    break;
                }
            }
        }
        else
        {
            Node *current = this->head;
            for (int i = 0; i < index - 1; ++i)
            {
                current = current->next;
            }
            Node *mem = current->next;
            current->next = newNode;
            newNode->next = mem;
        }
        ++this->size;
    }

    void deleteAtIndex(int index)
    {
        if (index >= this->size || index < 0)
        {
            return;
        }
        if (index == 0)
        {
            Node *mem = this->head;
            this->head = mem->next;
            delete mem;
        }
        else
        {
            Node *current = this->head;
            for (int i = 0; i < index - 1; ++i)
            {
                current = current->next;
            }
            Node *mem = current->next;
            current->next = mem->next;
            delete mem;
        }
        --this->size;
    }
};
