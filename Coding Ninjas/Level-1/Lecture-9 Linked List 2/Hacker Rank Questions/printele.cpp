#include <iostream>
using namespace std;

class SinglyLinkedList
{
public:
    int data;
    SinglyLinkedList *next;

    SinglyLinkedList(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void printLinkedList(SinglyLinkedList *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << endl;
    printLinkedList(head->next);
    return;
}

int main()
{
}
