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

int findNodeRec(Node *head, int n)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == n)
    {
        return 0;
    }
    int ans = findNodeRec(head->next, n);
    if (ans == -1)
    {
        return -1;
    }
    return ans + 1;
}

int main()
{
    return 0;
}