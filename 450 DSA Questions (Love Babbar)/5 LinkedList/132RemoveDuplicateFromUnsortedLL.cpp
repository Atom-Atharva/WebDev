// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

// Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

#include <iostream>
using namespace std;
#include <unordered_map>

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
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        // Base Case--
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // HashMap for storing values--
        unordered_map<int, bool> seen;
        seen[head->data] = 1; // Store first List Data into Hashmap--

        // Iterate Over LL--
        Node *curr = head->next;
        Node *prev = head;
        while (curr != NULL)
        {
            // Check for Duplicate--
            if (seen[curr->data] == 1)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                seen[curr->data] = 1;
                curr = curr->next;
                prev = prev->next;
            }
        }
        return head;
    }
};