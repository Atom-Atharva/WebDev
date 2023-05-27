// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

// Given a linked list of N nodes. The task is to reverse this list.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Solution
{

    pair<Node *, Node *> reverseListHelper(Node *head)
    {
        // Base Case--
        if (head == NULL || head->next == NULL)
        {
            return {head, head};
        }

        // Reccursive Call--
        pair<Node *, Node *> temp = reverseListHelper(head->next);

        // Place head to last of the Reversed LL--
        temp.second->next = head;
        head->next = NULL;

        // Return new head--
        return {temp.first, head};
    }

public:
    // Function to reverse a linked list.
    Node *reverseList(struct Node *head)
    {
        return reverseListHelper(head).first;
    }
};