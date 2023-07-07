// P12. Write a program to implement a stack with push, pop, peek and getLength
// operations. Implement it using a linked list.

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
class StackUsingLL
{
    Node<T> *head;
    int size;

public:
    StackUsingLL()
    {
        head = NULL;
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

    void push(T element)
    {
        Node<T> *newNode = new Node<T>(element);

        newNode->next = head;
        head = newNode;
        size++;
        return;
    }

    T pop()
    {
        if (head == NULL)
        {
            cout << -1 << endl;
            return 0;
        }

        T ans = head->data;
        Node<T> *later = head->next;
        delete head;
        head = later;
        size--;
        return ans;
    }

    T top()
    {
        if (head == NULL)
        {
            cout << -1 << endl;
            return 0;
        }
        return head->data;
    }
};