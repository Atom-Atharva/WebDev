// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

//   Definition for singly-linked list.
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *temp = head;
        ListNode *prev = head;
        while (temp->next != NULL)
        {
            if (temp->next->val == temp->val)
            {
                if (temp == head)
                {
                    head = temp->next;
                    delete temp;
                    temp = head;
                    prev = head;
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
            }
            else
            {
                if (temp != head)
                {
                    prev = prev->next;
                }
                temp = temp->next;
            }
        }
        return head;
    }
};