// https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1

// Given a Binary Search Tree, modify the given BST such that it is balanced and has minimum possible height.

// Examples :

// Input:
//        30
//       /
//      20
//     /
//    10
// Output:
//      20
//    /   \
//  10     30

// Input:
//          4
//         /
//        3
//       /
//      2
//     /
//    1
// Output:
//       3            3           2
//     /  \         /  \        /  \
//    1    4   OR  2    4  OR  1    3   OR ..
//     \          /                   \
//      2        1                     4

#include <iostream>
using namespace std;
#include <vector>

// Structure of the Node of the BST is as
struct Node
{
    int data;
    Node *left, *right;
};

void findOrder(Node *root, vector<Node *> &order)
{
    // Base Case--
    if (root == NULL)
    {
        return;
    }

    // Reccursive Calls (INORDER)--
    findOrder(root->left, order);
    order.push_back(root);
    findOrder(root->right, order);

    return;
}

Node *buildBST(vector<Node *> order, int st, int en)
{
    // Base Case--
    if (st > en)
    {
        return NULL;
    }

    // Mid Node--
    int mid = (st + en) / 2;
    Node *root = order[mid];

    // Left Tree--
    root->left = buildBST(order, st, mid - 1);

    // Right Tree--
    root->right = buildBST(order, mid + 1, en);

    return root;
}

// Your are required to complete this function
// function should return root of the modified BST
Node *buildBalancedTree(Node *root)
{
    // Put every node in vector--
    vector<Node *> order;
    findOrder(root, order);

    // Build Balanced BST--
    return buildBST(order, 0, order.size() - 1);
}
