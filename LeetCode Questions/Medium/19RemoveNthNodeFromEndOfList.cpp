// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>
using namespace std;

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int count = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        int node = count - n + 1;
        temp = head;
        if (node == 1)
        {
            head = head->next;
            delete temp;
            return head;
        }
        while (node > 2)
        {
            temp = temp->next;
            node--;
        }
        ListNode *temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
        return head;
    }
};