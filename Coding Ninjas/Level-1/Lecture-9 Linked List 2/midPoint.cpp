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

Node *midPoint(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    
    return 0;
}