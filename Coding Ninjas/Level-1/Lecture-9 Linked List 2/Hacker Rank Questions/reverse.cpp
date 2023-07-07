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

SinglyLinkedListNode *reverse(SinglyLinkedListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    SinglyLinkedListNode *subhead = reverse(head->next);
    SinglyLinkedListNode *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return subhead;
}

int main()
{
}
