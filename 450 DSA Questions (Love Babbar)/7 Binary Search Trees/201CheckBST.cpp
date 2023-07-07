// https://practice.geeksforgeeks.org/problems/check-for-bst/1

// Given the root of a binary tree. Check whether it is a BST or not.
// Note: We are considering that BSTs can not contain duplicate Nodes.
// A BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

//{ Driver Code Starts
#include <iostream>
using namespace std;
#include <climits>

// Tree Node
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
// } Driver Code Ends

// Check Range of the node--
class Solution
{
    bool isBST(Node *root, int min, int max)
    {
        // Base Case--
        if (root == NULL)
        {
            return true;
        }

        bool left = false;
        bool right = false;
        // Check Current Node--
        if (root->data >= min && root->data < max)
        {
            // Reccursive Calls--
            left = isBST(root->left, min, root->data);
            right = isBST(root->right, root->data, max);
        }

        return left && right;
    }

public:
    bool isBST(Node *root)
    {
        return isBST(root, INT_MIN, INT_MAX);
    }
};

// Wrong Answer--
// class Solution
// {
// public:
//     // Function to check whether a Binary Tree is BST or not.
//     bool isBST(Node *root)
//     {
//         if (root == NULL)
//         {
//             return true;
//         }

//         bool right = isBST(root->right);
//         bool left = isBST(root->left);

//         bool check = true;
//         if (root->left != NULL)
//         {
//             if (root->left->data > root->data)
//             {
//                 check = false;
//             }
//         }
//         if (root->right != NULL)
//         {
//             if (root->right->data < root->data)
//             {
//                 check = false;
//             }
//         }

//         return check && right && left;
//     }
// };
