// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

// Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

#include <iostream>
using namespace std;

// Reverse a linked list
//   The input list will have at least one element
//   Return the node which points to the head of the new LinkedList
//   node is defined as
struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
    pair<node *, node *> reverseListHelper(node *head, int k, int pt)
    {
        // Base Case--
        if (head == NULL || head->next == NULL)
        {
            return {head, head};
        }

        // Reccursive Call--
        pair<node *, node *> temp = reverseListHelper(head->next, k, (pt % k) + 1);

        // Place head to last of the Reversed LL--
        if (pt == k)
        {
            head->next = temp.first;
            temp.first = head;
            temp.second = head;
        }
        else
        {
            node *curr = temp.second->next;
            temp.second->next = head;
            head->next = curr;
            temp.second = head;
        }

        // Return new head--
        return temp;
    }

public:
    struct node *reverse(struct node *head, int k)
    {
        return reverseListHelper(head, k, 1).first;
    }
};