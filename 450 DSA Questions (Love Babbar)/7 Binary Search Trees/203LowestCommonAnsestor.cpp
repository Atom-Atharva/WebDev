// https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

// Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

// Example 1:

// Input:
//               5
//             /   \
//           4      6
//          /        \
//         3          7
//                     \
//                      8
// n1 = 7, n2 = 8
// Output: 7

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to find the lowest common ancestor in a BST.
class Solution
{
public:
    Node *LCA(Node *root, int n1, int n2)
    {
        int minimum = min(n1, n2);
        int maximum = max(n1, n2);

        // Base Case--
        if (root == NULL)
        {
            return root;
        }
        if (root->data >= minimum && root->data <= maximum)
        {
            return root;
        }

        // Select a route--
        Node *ancestor = NULL;
        if (minimum > root->data)
        {
            ancestor = LCA(root->right, minimum, maximum);
        }
        if (maximum < root->data)
        {
            ancestor = LCA(root->left, minimum, maximum);
        }

        return ancestor;
    }
};
