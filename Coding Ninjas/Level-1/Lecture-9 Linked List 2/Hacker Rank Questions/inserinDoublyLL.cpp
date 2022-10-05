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

DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *head, int data)
{
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    DoublyLinkedListNode *curr = head;
    if (head->data > data)
    {
        curr->prev = newNode;
        newNode->next = curr;
        head = newNode;
        return head;
    }
    while (curr->next != NULL)
    {
        if (curr->next->data < data)
        {
            curr = curr->next;
        }
        else
        {
            break;
        }
    }
    if (curr->next == NULL)
    {
        curr->next = newNode;
        newNode->prev = curr;
        return head;
    }
    DoublyLinkedListNode *temp = curr->next;
    curr->next = newNode;
    newNode->next = temp;
    temp->prev = newNode;
    newNode->prev = curr;
    return head;
}

int main()
{
}