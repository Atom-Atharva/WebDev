#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

/* Time Complexity of the code in O(n2),
so it is not advisable to you this approach*/

Node *reverseLinkedListRec(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *subhead = reverseLinkedListRec(head->next);
    Node *temp = subhead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return subhead;
}

int main()
{
    return 0;
}