#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

/* AS the head contain the address of the last element after recursion process,
we simply created the tail pointer and stored the address of head->next in it
And we got the last element of the list after recursion. */

Node *reverseLL_3(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *subhead = reverseLL_3(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return subhead;
}

int main()
{
    return 0;
}