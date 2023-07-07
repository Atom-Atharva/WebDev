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

SinglyLinkedListNode *deleteNode(SinglyLinkedListNode *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }
    if (pos == 0)
    {
        SinglyLinkedListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    if (pos == 1)
    {
        SinglyLinkedListNode *temp = head->next;
        head->next = temp->next;
        delete temp;
        return head;
    }
    SinglyLinkedListNode *subhead = deleteNode(head->next, pos - 1);
    head->next = subhead;
    return head;
}

int main()
{
}
