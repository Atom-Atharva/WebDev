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

Node *mergeTwoSortedLinkedList(Node *head1, Node *head2)
{
    Node *fhead = NULL;
    Node *ftail = NULL;

    if (head1 == NULL && head2 == NULL)
    {
        return fhead;
    }
    if (head1 == NULL && head2 != NULL)
    {
        return head2;
    }
    if (head2 == NULL && head1 != NULL)
    {
        return head1;
    }
    if (head1->data < head2->data)
    {
        fhead = head1;
        ftail = head1;
        head1 = head1->next;
    }
    else
    {
        fhead = head2;
        ftail = head2;
        head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            ftail->next = head1;
            ftail = head1;
            head1 = head1->next;
        }
        else
        {
            ftail->next = head2;
            ftail = head2;
            head2 = head2->next;
        }
    }
    if (head1 != NULL)
    {
        ftail->next = head1;
    }
    else if (head2 != NULL)
    {
        ftail->next = head2;
    }
    return fhead;
}

int main()
{
    return 0;
}