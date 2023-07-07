// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

#include <iostream>
using namespace std;
#include <unordered_map>

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        unordered_map<int, int> element;
        ListNode *curr = head;
        while (curr != NULL)
        {
            if (element.count(curr->val) > 0)
            {
                element[curr->val]++;
            }
            else
            {
                element[curr->val] = 1;
            }
            curr = curr->next;
        }

        curr = head;
        ListNode *prev = head;

        while (curr != NULL)
        {
            // Base Case--
            if (curr == head)
            {
                if (element[curr->val] > 1)
                {
                    head = head->next;
                    ListNode *temp = curr;
                    curr = curr->next;
                    prev = head;
                    delete temp;
                }
                else
                {
                    curr = curr->next;
                }
                continue;
            }

            if (element[curr->val] > 1)
            {
                ListNode *temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
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