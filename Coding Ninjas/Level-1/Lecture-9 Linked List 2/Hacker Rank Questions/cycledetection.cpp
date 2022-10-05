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

bool has_cycle(SinglyLinkedListNode *head)
{
    SinglyLinkedListNode *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
}
