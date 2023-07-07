// https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1

// Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.

// Example 1:

// Input:
//       1
//     /   \
//    2     3
// Output: 1 2 3

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    void findOrder(Node *root, vector<int> &order)
    {
        // Base Case--
        if (root == NULL)
        {
            return;
        }

        // Insert root in vector--
        order.push_back(root->data);

        // Reccursive Calls--
        findOrder(root->left, order);
        findOrder(root->right, order);

        return;
    }

    Node *BST(vector<int> order, int st, int en)
    {
        // Base Case--
        if (st > en)
        {
            return NULL;
        }

        // Finding Middle--
        int mid = (st + en) / 2;
        Node *root = new Node(order[mid]);

        // Reccursive Calls--
        Node *left = BST(order, st, mid - 1);
        Node *right = BST(order, mid + 1, en);

        // Establish Connections--
        root->left = left;
        root->right = right;

        return root;
    }

public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST(Node *root)
    {
        vector<int> order;

        // Find Order--
        findOrder(root, order);

        // Sort Array--
        sort(order.begin(), order.end());

        // Making BST--
        return BST(order, 0, order.size() - 1);
    }
};