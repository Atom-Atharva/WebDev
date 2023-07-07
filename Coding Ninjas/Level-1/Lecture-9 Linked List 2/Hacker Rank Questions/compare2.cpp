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

bool compare_lists(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    if ((head1 == NULL && head2 != NULL) || (head1 != NULL && head2 == NULL))
    {
        return 0;
    }
    if (head1 == NULL && head2 == NULL)
    {
        return 1;
    }
    bool prev = compare_lists(head1->next, head2->next);
    if (prev)
    {
        if (head1->data != head2->data)
        {
            return 0;
        }
        return 1;
    }
    return 0;
}

int main()
{
}
