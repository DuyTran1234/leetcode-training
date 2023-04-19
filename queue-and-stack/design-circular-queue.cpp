#include <vector>
using namespace std;

class MyCircularQueue
{
private:
    int head = 0;
    int tail = -1;
    int max_size;
    vector<int> queue;

public:
    MyCircularQueue(int k)
    {
        this->max_size = k;
        queue.resize(k);
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }
        this->tail = (this->tail + 1) % max_size;
        queue[this->tail] = value;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }
        if (head == tail)
        {
            this->head = 0;
            this->tail = -1;
        }
        else
        {
            this->head = (this->head + 1) % max_size;
        }
        return true;
    }

    int Front()
    {
        return isEmpty() ? -1 : queue[head];
    }

    int Rear()
    {
        return isEmpty() ? -1 : queue[tail];
    }

    bool isEmpty()
    {
        return this->tail == -1;
    }

    bool isFull()
    {
        return !isEmpty() && (tail + 1) % max_size == head;
    }
};