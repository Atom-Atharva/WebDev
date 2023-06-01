// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

// Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.

// For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

#include <iostream>
using namespace std;
#include <vector>

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
    // Reverse an array--
    void reverse(vector<int> &arr)
    {
        for (int i = 0; i < arr.size() / 2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[arr.size() - 1 - i];
            arr[arr.size() - 1 - i] = temp;
        }
        return;
    }

    // Make LL using array--
    Node *makeLL(vector<int> sum)
    {
        Node *head = new Node(sum[0]);
        Node *curr = head;
        for (int i = 1; i < sum.size(); i++)
        {
            Node *temp = new Node(sum[i]);
            curr->next = temp;
            curr = curr->next;
        }

        return head;
    }

public:
    Node *addTwoLists(Node *first, Node *second)
    {
        // Make vector from first list--
        vector<int> num1;
        while (first != NULL)
        {
            num1.push_back(first->data);
            first = first->next;
        }
        reverse(num1);

        // Make vector from second list--
        vector<int> num2;
        while (second != NULL)
        {
            num2.push_back(second->data);
            second = second->next;
        }
        reverse(num2);

        // Add 2 vectors--
        int carry = 0;

        vector<int> sum(max(num1.size(), num2.size()), 0);
        int i;
        for (i = 0; i < min(num1.size(), num2.size()); i++)
        {
            sum[i] = (num1[i] + num2[i] + carry) % 10;
            carry = (num1[i] + num2[i] + carry) / 10;
        }

        // Handle Remaining Numbers--
        if (num1.size() > num2.size())
        {
            for (i; i < num1.size(); i++)
            {
                sum[i] = (num1[i] + carry) % 10;
                carry = (num1[i] + carry) / 10;
            }
        }
        if (num1.size() < num2.size())
        {
            for (i; i < num2.size(); i++)
            {
                sum[i] = (num2[i] + carry) % 10;
                carry = (num2[i] + carry) / 10;
            }
        }

        // Handle carry--
        if (carry != 0)
        {
            sum.push_back(carry);
        }
        reverse(sum);

        Node *head = makeLL(sum);
        return head;
    }
};

// Wrong Answer: As range of numbers are more than int--
// class Solution
// {
//     Node *makeLL(int sum)
//     {
//         // Base Case--
//         if (sum == 0 || sum / 10 == 0)
//         {
//             Node *head = new Node(sum);
//             return head;
//         }

//         // Reccursive Call--
//         Node *head = makeLL(sum / 10);

//         // Add last no to head--
//         Node *last = new Node(sum % 10);

//         // Traverse to last node--
//         Node *curr = head;
//         while (curr->next != NULL)
//         {
//             curr = curr->next;
//         }
//         curr->next = last;

//         return head;
//     }

// public:
//     // Function to add two numbers represented by linked list.
//     Node *addTwoLists(struct Node *first, struct Node *second)
//     {
//         int num1 = 0;
//         while (first != NULL)
//         {
//             num1 = num1 * 10 + first->data;
//             first = first->next;
//         }

//         int num2 = 0;
//         while (second != NULL)
//         {
//             num2 = num2 * 10 + second->data;
//             second = second->next;
//         }

//         int sum = num1 + num2;

//         Node *head = makeLL(sum);

//         return head;
//     }
// };