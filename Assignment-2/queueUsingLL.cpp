// P17. Write a program to implement a Queue with enqueue, dequeue, isEmpty and
// getLength operations. Use a link list for storing elements of the queue.

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Queue
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }
        tail->next = newNode;
        tail = tail->next;
        size++;
        return;
    }

    T dequeue()
    {
        if (head == NULL)
        {
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head->next;
        delete head;
        head = temp;
        size--;
        return ans;
    }
    T front()
    {
        if (head == NULL)
        {
            return 0;
        }
        return head->data;
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    cout << q.getSize() << endl;

    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.getSize() << endl;

    cout << q.isEmpty() << endl;

    return 0;
}