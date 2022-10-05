#include <iostream>
using namespace std;

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
            T *newData = new T[2 * capacity];
            int j = 0;
            for (int i = start; i < capacity; i++, j++)
            {
                newData[j] = data[i];
            }
            for (int i = 0; i < start; i++, j++)
            {
                newData[j] = data[i];
            }
            delete[] data;
            data = newData;
            start = 0;
            end = capacity;
            capacity *= 2;
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

int main()
{
    QueueUsingArray<int> q(5);

    (q.isEmpty()) ? cout << "True\n" : cout << "False\n";

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    cout << q.getSize() << endl;

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    (q.isEmpty()) ? cout << "True\n" : cout << "False\n";
    cout << q.front() << endl;

    cout << q.getSize() << endl;

    return 0;
}