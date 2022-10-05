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

Node *reverseLL(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *upcom = NULL;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    while (curr != NULL)
    {
        upcom = curr->next;
        curr->next = prev;
        prev = curr;
        curr = upcom;
    }
    return prev;
}

int main()
{
    return 0;
}