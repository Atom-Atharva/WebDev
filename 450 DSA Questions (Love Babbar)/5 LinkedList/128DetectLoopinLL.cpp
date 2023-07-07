// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

// Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.

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
    // Function to check if the linked list has a loop.
    bool detectLoop(Node *head)
    {
        // Fast & Slow pointer approach--
        // Fast moves 2 spaces and slow moves 1 space at a time--
        Node *fast = head;
        Node *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                return 1;
            }
        }
        return 0;
    }
};