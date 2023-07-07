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

Node *skipMdeleteN(Node *head, int M, int N)
{
    if (head == NULL)
    {
        return head;
    }
    if (M == 0)
    {
        return NULL;
    }
    if (N == 0)
    {
        return head;
    }
    Node *curr = head;
    Node *prev = head;

    int skip = 1;
    int del = 1;
    while (curr != NULL)
    {
        while (curr != NULL && skip <= M)
        {
            prev = curr;
            curr = curr->next;
            skip++;
        }
        if (skip > M && del <= N)
        {
            del++;
            prev->next = curr->next;
            delete curr;
            curr = curr->next;
        }
        if (del > N)
        {
            skip = 1;
            del = 1;
        }
    }
    return head;
}

int main()
{
    return 0;
}