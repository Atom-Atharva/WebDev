#include <iostream>
using namespace std;

class DoublyLinkedListNode
{
public:
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;

    DoublyLinkedListNode(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

DoublyLinkedListNode *reverse(DoublyLinkedListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    DoublyLinkedListNode *subhead = reverse(head->next);
    DoublyLinkedListNode *tail = head->next;
    tail->next = head;
    head->prev = tail;
    head->next = NULL;
    return subhead;
}

int main()
{
}