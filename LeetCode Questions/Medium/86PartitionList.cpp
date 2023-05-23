// https://leetcode.com/problems/partition-list/

// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions

#include <iostream>
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
    ListNode *partition(ListNode *head, int x)
    {
        // Base Case--
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Make 2 Link Lists (less than x and greater than x)--
        ListNode *head1 = NULL, *head2 = NULL;
        ListNode *tail1 = NULL, *tail2 = NULL;

        while (head != NULL)
        {
            ListNode *temp = new ListNode(head->val);
            if (head->val < x)
            {
                if (head1 == NULL)
                {
                    head1 = temp;
                    tail1 = temp;
                }
                else
                {
                    tail1->next = temp;
                    tail1 = tail1->next;
                }
            }
            else
            {
                if (head2 == NULL)
                {
                    head2 = temp;
                    tail2 = temp;
                }
                else
                {
                    tail2->next = temp;
                    tail2 = tail2->next;
                }
            }
            head = head->next;
        }

        // Combine 2 Lists--
        if (head1 == NULL)
        {
            head1 = head2;
        }
        else
        {
            tail1->next = head2;
        }

        return head1;
    }
};