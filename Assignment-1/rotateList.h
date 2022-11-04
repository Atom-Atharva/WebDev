// P9. Write a function with following signature
// void rotate(node *t )
// The function takes node pointer of “start” (first node of link list) and rotate the elements
// in the list as shown in following example:
// List t { a1, a2, a3, a4, a5, a6}
// List after rotate { a2, a3, a4, a5, a6, a1}

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = data;
        next = NULL;
    }
};

Node *rotate(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head = head->next;
    temp->next->next = NULL;
    return head;
}