// https://leetcode.com/problems/merge-two-sorted-lists/description/

// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

#include <iostream>
using namespace std;

//  Definition for singly-linked list.
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL && list2 == NULL)
        {
            return NULL;
        }
        if (list1 == NULL)
        {
            return list2;
        }
        if (list2 == NULL)
        {
            return list1;
        }

        ListNode *head = NULL;
        ListNode *temp = NULL;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                if (head == NULL)
                {
                    head = list1;
                    temp = head;
                    list1 = list1->next;
                    continue;
                }
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
            else
            {
                if (head == NULL)
                {
                    head = list2;
                    temp = head;
                    list2 = list2->next;
                    continue;
                }
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }

        if (list1 != NULL)
        {
            temp->next = list1;
        }
        if (list2 != NULL)
        {
            temp->next = list2;
        }

        return head;
    }
};