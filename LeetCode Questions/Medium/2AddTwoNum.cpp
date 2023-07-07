// https://leetcode.com/problems/add-two-numbers/

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#include<iostream>
using namespace std;

//   Definition for singly-linked list.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        if (l1 == NULL && l2 != NULL)
        {
            return l2;
        }
        if (l2 == NULL && l1 != NULL)
        {
            return l1;
        }

        ListNode *ans = NULL;
        ListNode *temp = ans;
        int carry = 0;
        while (l1 != NULL && l2 != NULL)
        {
            ListNode *newNode = new ListNode((l1->val + l2->val + carry) % 10);
            if (ans == NULL)
            {
                ans = newNode;
                temp = ans;
            }
            else
            {
                temp->next = newNode;
                temp = temp->next;
            }
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL)
        {
            ListNode *newNode = new ListNode((l1->val + carry) % 10);
            temp->next = newNode;
            temp = temp->next;
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            ListNode *newNode = new ListNode((l2->val + carry) % 10);
            temp->next = newNode;
            temp = temp->next;
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
        }
        if (carry != 0)
        {
            ListNode *newNode = new ListNode(carry);
            temp->next = newNode;
        }

        return ans;
    }
};