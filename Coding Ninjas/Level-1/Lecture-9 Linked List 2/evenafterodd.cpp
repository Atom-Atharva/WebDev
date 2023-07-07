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

Node *evenAfterOdd(Node *head)
{
    Node *oh = NULL;
    Node *ot = NULL;
    Node *eh = NULL;
    Node *et = NULL;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data % 2 != 0)
        {
            if (oh == NULL)
            {
                oh = curr;
                ot = curr;
            }
            else
            {
                ot->next = curr;
                ot = curr;
            }
        }
        else
        {
            if (eh == NULL)
            {
                eh = curr;
                et = curr;
            }
            else
            {
                et->next = curr;
                et = curr;
            }
        }
        curr = curr->next;
    }
    if (oh == NULL)
    {
        et->next = NULL;
        return eh;
    }
    if (eh == NULL)
    {
        return oh;
    }

    et->next = NULL;
    ot->next = eh;

    return oh;
}

int main()
{
    return 0;
}