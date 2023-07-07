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
    {
        return 0;
    }
    int ans = length(head->next);
    return ans + 1;
}

int getNode(SinglyLinkedListNode *head, int pos)
{
    int len = length(head);
    pos = len - 1 - pos;

    int count = 0;
    while (count < pos)
    {
        head = head->next;
        count++;
    }
    return head->data;
}

int main()
{
}
