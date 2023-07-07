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

int main()
{
    StackUsingLL<char> s;

    s.push(100);
    s.push(104);
    s.push(122);
    s.push(97);
    s.push(65);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.getSize() << endl;

    cout << s.isEmpty() << endl;
}