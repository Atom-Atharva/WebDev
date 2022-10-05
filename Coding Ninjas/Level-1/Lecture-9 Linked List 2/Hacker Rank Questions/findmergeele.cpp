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

int length(SinglyLinkedListNode *head)
{
    if (head == NULL)
        return 0;

    int ans = length(head->next);
    return ans + 1;
}

int findMergeNode(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    int len1 = length(head1);
    int len2 = length(head2);

    SinglyLinkedListNode *curr1 = head1, *curr2 = head2;
    if (len1 > len2)
    {
        int diff = len1 - len2;
        while (diff--)
        {
            curr1 = curr1->next;
        }
    }
    else if (len2 > len1)
    {
        int diff = len2 - len1;
        while (diff--)
        {
            curr2 = curr2->next;
        }
    }

    while (curr1 != curr2)
    {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return curr1->data;
}

int main()
{
}
