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

SinglyLinkedListNode *insertNodeAtPosition(SinglyLinkedListNode *head, int data, int pos)
{
    if (head == NULL || pos == 0)
    {
        SinglyLinkedListNode *p = new SinglyLinkedListNode(data);
        p->next = head;
        head = p;
        return head;
    }

    if (pos == 1)
    {
        SinglyLinkedListNode *p = new SinglyLinkedListNode(data);
        p->next = head->next;
        head->next = p;
        return head;
    }
    SinglyLinkedListNode *subhead = insertNodeAtPosition(head->next, data, pos - 1);
    head->next = subhead;
    return head;
}

int main()
{
}
