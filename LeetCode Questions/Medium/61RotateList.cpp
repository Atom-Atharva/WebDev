// https://leetcode.com/problems/rotate-list/

// Given the head of a linked list, rotate the list to the right by k places.

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        // Base Case--
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Calculate total nodes--
        int n = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            n++;
        }

        // Make k smaller than n--
        k = k % n;

        temp = head;
        for (int i = 1; i < n - k && temp->next != NULL; i++)
        {
            temp = temp->next;
        }

        // Check if last node--
        if (temp->next == NULL)
        {
            return head;
        }

        // Go to last node and connect with first--
        ListNode *temp2 = temp;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = head;
        head = temp->next;
        temp->next = NULL;

        cout << head->val << endl;
        return head;
    }
};