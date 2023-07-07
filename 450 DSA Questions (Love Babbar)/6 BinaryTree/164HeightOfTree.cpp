// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

// Given a binary tree, find its height.

// Example 1:

// Input:
//      1
//     /  \
//    2    3
// Output: 2

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to find the height of a binary tree.
    int height(struct Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int ltree = height(node->left);
        int rtree = height(node->right);

        return max(ltree, rtree) + 1;
    }
};