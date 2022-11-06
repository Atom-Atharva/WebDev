// P16. Write a program to implement a Queue with enqueue, dequeue, isEmpty, isFull
// and getLength operations. Use an array for storing elements of the queue.

template <typename T>
class QueueUsingArray
{
    T *data;
    int size;
    int start;
    int end;
    int capacity;

public:
    QueueUsingArray(int s)
    {
        data = new T[s];
        size = 0;

        // -1 Represent the Array is EMPTY
        start = -1;
        end = 0;
        capacity = s;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    T front()
    {
        if (size == 0)
        {
            cout << "QUEUE IS EMPTY\n";
            return 0;
        }
        return data[start];
    }

    T dequeue()
    {
        if (size == 0)
        {
            cout << "QUEUE IS EMPTY\n";
            return 0;
        }
        T ans = data[start];
        start = (start + 1) % capacity;
        size--;
        // if (size != 0 && start == capacity)
        // {
        //     start = 0;
        // }

        // Not necessary step but a good coder approach
        if (size == 0)
        {
            start = -1;
            end = 0;
        }

        return ans;
    }

    // Insert An ELEMENT
    void enqueue(T element)
    {
        if (size == capacity)
        {
            cout << "QUEUE FULL\n";
            return;
        }
        data[end] = element;
        end = (end + 1) % capacity;
        size++;
        if (start == -1)
        {
            start = 0;
        }
        // if (size != capacity && end == capacity)
        // {
        //     end = 0;
        // }
        return;
    }
};