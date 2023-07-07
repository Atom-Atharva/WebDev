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

SinglyLinkedListNode *insertNodeAtTail(SinglyLinkedListNode *head, int data)
{
    if (head == NULL)
    {
        SinglyLinkedListNode *p = new SinglyLinkedListNode(data);
        head = p;
        return head;
    }
    if (head->next == NULL)
    {
        SinglyLinkedListNode *p = new SinglyLinkedListNode(data);
        head->next = p;
        return head;
    }
    SinglyLinkedListNode *subhead = insertNodeAtTail(head->next, data);
    head->next = subhead;
    return head;
}

int main()
{
}
