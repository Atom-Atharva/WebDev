// P4. Write a function to append a link list at last to another and return the start pointer to the result list.
// node * append ( node* start1, node * start2)
// // start1 and start2 are the first node pointer of two list

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

class Append
{
    Node *head;

public:
    Append()
    {
        head == NULL;
    }

    Node *append(Node *head1, Node *head2)
    {
        if (head1 == NULL && head2 == NULL)
        {
            return NULL;
        }
        if (head1 == NULL)
        {
            return head2;
        }
        if (head2 == NULL)
        {
            return head1;
        }
        Node *temp = head1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head2;
        return head1;
    }
};
