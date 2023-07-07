// https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

// Given a Binary Tree, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.

// Example 1:

// Input:
//            10
//        /  \
//       8    12
//      /
//     3

// Output: 3->8 8->10 10->12 12->-1
// Explanation: The inorder of the above tree is :
// 3 8 10 12. So the next pointer of node 3 is
// pointing to 8 , next pointer of 8 is pointing
// to 10 and so on.And next pointer of 12 is
// pointing to -1 as there is no inorder successor
// of 12.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

// Method 2: Storing Prev Node--
class Solution
{
public:
    void helper(Node *root, Node *&prev)
    {
        // Base Case--
        if (root == NULL)
            return;

        // Call on Left Subtree--
        helper(root->left, prev);

        // Establish Connection--
        if (prev != NULL)
        {
            prev->next = root;
        }

        // Change prev to current node (INORDER)--
        prev = root;

        // Call on Right Subtree--
        helper(root->right, prev);
    }
    void populateNext(Node *root)
    {
        // code here
        Node *prev = NULL;
        helper(root, prev);
    }
};

// Method 1: Min and Max, and Establish Connections--
class Solution
{
    // Pair<Right most of Left Tree, LeftMost of Right Tree>
    // Helper Function--
    pair<Node *, Node *> populate(Node *root)
    {
        // Base Case--
        if (root == NULL)
        {
            return {NULL, NULL};
        }

        // Left Tree--
        pair<Node *, Node *> left = {root, root};
        if (root->left != NULL)
        {
            left = populate(root->left);
        }

        // Right Tree--
        pair<Node *, Node *> right = {root, root};
        if (root->right != NULL)
        {
            right = populate(root->right);
        }

        // Create Connections--
        if (left.second != root)
        {
            left.second->next = root;
        }
        if (right.first != root)
        {
            root->next = right.first;
        }

        // Return Smallest and Largest of Tree--
        return {left.first, right.second};
    }

public:
    void populateNext(Node *root)
    {
        // Call Helper Function--
        pair<Node *, Node *> temp = populate(root);
        return;
    }
};