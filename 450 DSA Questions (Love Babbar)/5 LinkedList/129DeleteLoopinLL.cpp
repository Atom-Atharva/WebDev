// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

// Given a linked list of N nodes such that it may contain a loop.

// A loop here means that the last node of the link list is connected to the node at position X(1-based index). If the link list does not have any loop, X=0.

// Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        // Slow and Fast Pointers--
        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                fast = head;
                break;
            }
        }

        // Base Case (If no loop detected)--
        if (fast == NULL || fast->next == NULL)
        {
            return;
        }

        // Base Case (If intersection is on head)--
        if (slow == head)
        {
            while (slow->next != head)
            {
                slow = slow->next;
            }
        }

        else
        {
            // Intersection point will give intersection of loop in LL--
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        slow->next = NULL;

        return;
    }
};