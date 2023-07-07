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

SinglyLinkedListNode *removeDublicates(SinglyLinkedListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    SinglyLinkedListNode *curr = head;
    SinglyLinkedListNode *upcom = head->next;

    while (upcom != NULL)
    {
        if (upcom->data == curr->data)
        {
            curr->next = upcom->next;
            delete upcom;
            upcom = curr->next;
        }
        else
        {
            curr = upcom;
            upcom = curr->next;
        }
    }
    return head;
}

int main()
{
}
