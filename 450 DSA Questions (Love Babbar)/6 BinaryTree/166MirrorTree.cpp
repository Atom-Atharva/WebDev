// https://practice.geeksforgeeks.org/problems/mirror-tree/1

// Given a Binary Tree, convert it into its mirror.

// Example 1:

// Input:
//       1
//     /  \
//    2    3
// Output: 3 1 2
// Explanation: The tree is
//    1    (mirror)  1
//  /  \    =>      /  \
// 2    3          3    2
// The inorder of mirror is 3 1 2

#include <iostream>
using namespace std;

//  A binary tree node has data, pointer to left child
//  and a pointer to right child.
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
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node *node)
    {
        // Base Case--
        if (node == NULL)
        {
            return;
        }

        // Reccursive Call--
        mirror(node->left);
        mirror(node->right);

        // Swap Curr Childrens--
        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;

        return;
    }
};