// P6. Write a function to return the pointer to the middle node of a link list given its start
// pointer. Use fast and slow pointer method to find the middle node.
// node * middle (node *start)

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

class FindMiddle
{
    Node *head;

public:
    FindMiddle()
    {
        head = NULL;
    }

    Node *middle(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *fast = head, *slow = head;
        while (fast != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};