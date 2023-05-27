// https://practice.geeksforgeeks.org/problems/44bb5287b98797782162ffe3d2201621f6343a4b/1

// Given a singly linked list of N nodes. Find the first node of the loop if the linked list has a loop. If a loop is present return the node data of the first node of the loop else return -1.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to find first node if the linked list has a loop.
    int findFirstNode(Node *head)
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
            return -1;
        }

        // Intersection point will give intersection of loop in LL--
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }
};
