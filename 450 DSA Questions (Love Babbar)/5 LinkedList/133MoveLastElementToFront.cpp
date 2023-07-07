// https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/

// Write a function that moves the last node to the front in a given Singly Linked List.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *moveLastToFirst(Node *head)
    {
        // Base Case--
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Find Second Last Node--
        Node *curr = head;
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }

        // Disjoin Last Node from LL--
        Node *last = curr->next;
        curr->next = NULL;

        // Join Last Node to First--
        last->next = head;
        head = last;

        return head;
    }
};