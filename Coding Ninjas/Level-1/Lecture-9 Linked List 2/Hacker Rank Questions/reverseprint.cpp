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

void reversePrint(SinglyLinkedListNode *head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        cout << head->data << endl;
        return;
    }
    reversePrint(head->next);
    cout << head->data << endl;
    return;
}

int main()
{
}
