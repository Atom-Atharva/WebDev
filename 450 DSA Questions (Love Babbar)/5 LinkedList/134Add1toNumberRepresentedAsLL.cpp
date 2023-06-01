// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

// A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
    Node *addOne(Node *head, Node *prev, bool &update)
    {
        // Base Case--
        if (head == NULL)
        {
            return head;
        }
        if (head->next == NULL)
        {
            head->data++;
            int carry = head->data / 10;
            head->data = head->data % 10;

            if (carry > 0)
            {
                update = true;
                if (prev == NULL)
                {
                    prev = new Node(carry);
                    prev->next = head;
                    head = prev;
                }
            }
            return head;
        }

        // Reccursive Call--
        Node *newhead = addOne(head->next, head, update);
        if (update)
        {
            head->data++;
            int carry = head->data / 10;
            head->data = head->data % 10;

            if (carry > 0)
            {
                update = true;
                if (prev == NULL)
                {
                    prev = new Node(carry);
                    prev->next = head;
                    head = prev;
                }
            }
            else
            {
                update = false;
            }
        }

        // return head of list after adding one
        return head;
    }

public:
    Node *addOne(Node *head)
    {
        bool update = false;
        return addOne(head, NULL, update);
    }
};