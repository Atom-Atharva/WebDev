#include <iostream>
using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int data)
    {
        this->data = data;
        next = NULL;
    }
};

SinglyLinkedListNode *mergeLists(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    SinglyLinkedListNode *c1 = head1;
    SinglyLinkedListNode *c2 = head2;
    SinglyLinkedListNode *newhead = NULL;
    SinglyLinkedListNode *newtail = NULL;

    while (c1 != NULL && c2 != NULL)
    {
        if (newhead == NULL)
        {
            if (c1->data < c2->data)
            {
                newhead = c1;
                newtail = c1;
                c1 = c1->next;
            }
            else
            {
                newhead = c2;
                newtail = c2;
                c2 = c2->next;
            }
        }
        else
        {
            if (c1->data < c2->data)
            {
                newtail->next = c1;
                newtail = c1;
                c1 = c1->next;
            }
            else
            {
                newtail->next = c2;
                newtail = c2;
                c2 = c2->next;
            }
        }
    }
    if (c1 != NULL)
    {
        newtail->next = c1;
    }
    if (c2 != NULL)
    {
        newtail->next = c2;
    }
    return newhead;
}

int main()
{
}
