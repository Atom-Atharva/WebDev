// https://leetcode.com/problems/swap-nodes-in-pairs/

// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // Optimized Solution--
    // Reccursive Approach--
    ListNode *swapPairs(ListNode *head)
    {
        // if head is NULL OR just having a single node, then no need to change anything
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *temp;    // temporary pointer to store head -> next
        temp = head->next; // give temp what he want

        head->next = swapPairs(head->next->next); // changing links
        temp->next = head;                        // put temp -> next to head

        return temp; // now after changing links, temp act as our head
    }

    // Naive Solution--
    // Itterative Approach--
    // ListNode *swapPairs(ListNode *head)
    // {
    //     // Base Case--
    //     if (head == NULL || head->next == NULL)
    //     {
    //         return head;
    //     }

    //     ListNode *curr = head;
    //     ListNode *after = head;
    //     head = head->next;
    //     ListNode *prev = head;

    //     while (curr != NULL && curr->next != NULL)
    //     {
    //         after = curr->next;

    //         // Swapping and Connections--
    //         curr->next = after->next;
    //         after->next = curr;
    //         if (prev != head)
    //         {
    //             prev->next = after;
    //         }

    //         // Updating pointers--
    //         prev = curr;
    //         curr = curr->next;
    //     }
    //     return head;
    // }
};