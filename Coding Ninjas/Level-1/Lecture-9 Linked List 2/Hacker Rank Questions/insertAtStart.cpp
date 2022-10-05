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

SinglyLinkedListNode *insertNodeAtHead(SinglyLinkedListNode *head, int data)
{
    SinglyLinkedListNode *p = new SinglyLinkedListNode(data);
    p->next = head;
    head = p;

    return head;
}

int main()
{
}
