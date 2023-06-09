// https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1

// Given a Binary Search Tree. The task is to find the minimum valued element in this given BST.

// Function to find the minimum element in the given BST.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

class Solution
{
public:
    // Go to leftest node--
    int minValue(Node *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        if (root->left == NULL)
        {
            return root->data;
        }

        int min = minValue(root->left);

        return min;
    }
};