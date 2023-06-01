// https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

// Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
// Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

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
    Node *removeDuplicates(Node *head)
    {
        // Base Case--
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Iteration over LL.
        Node *curr = head->next;
        Node *prev = head;
        while (curr != NULL)
        {
            // Check for Duplicate--
            if (curr->data == prev->data)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                curr = curr->next;
                prev = prev->next;
            }
        }

        return head;
    }
};