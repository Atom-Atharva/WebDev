// P8. Write a function with following signature
// node* alterneteMerge(node *t1 ,node* t2)
// The function takes two node pointers of “start” (first node of link list) and returns “start”
// pointer of resulting link list. Resulting link list is to be created using element values from
// the two lists ( t1 and t2) in alternate fashion. Example :
// List t1 { a1, a2, a3, a4}
// List t2 { b1, b2, b3, b4, b5, b6}
// Result List { a1, b1, a2, b2, a3, b3, a4, b4, b5, b6}

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

Node *alternateMerge(Node *head1, Node *head2)
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
    Node *p1 = head1, *p2 = head2;
    bool up = false;
    Node *newh = p1, *newt = p1;
    while (p1 != NULL || p2 != NULL)
    {
        if (up)
        {
            newt->next = p1;
            newt = p1;
            p1 = p1->next;
            up = false;
        }
        else
        {
            newt->next = p2;
            newt = p2;
            p2 = p2->next;
            up = true;
        }
    }
    if (p1 != NULL)
    {
        newt->next = p1;
    }
    if (p2 != NULL)
    {
        newt->next = p2;
    }
    return newh;
}