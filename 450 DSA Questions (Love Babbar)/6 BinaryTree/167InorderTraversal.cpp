// https://www.techiedelight.com/?problem=InorderTreeTraversal

/*

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Input:
           1
         /   \
        /	  \
       2	   3
      /		  / \
     /	  	 /	 \
    4		5	  6
           / \
          /   \
         7	   8

Output: [4, 2, 1, 7, 5, 8, 3, 6]

*/

#include <iostream>
using namespace std;
#include <vector>

// A binary tree node is defined as:
class Node
{
public:
    int data;                               // data field
    Node *left = nullptr, *right = nullptr; // pointer to the left and right child

    Node() {}
    Node(int data) : data(data) {}
    Node(int data, Node *left, Node *right) : data(data), left(left), right(right) {}
};

class Solution
{
    void inorderTraversal(Node *root, vector<int> &order)
    {
        // Base Case--
        if (root == NULL)
        {
            return;
        }

        // Reccursive Calls on Left Tree--
        inorderTraversal(root->left, order);

        // Push to Parent Node--
        order.push_back(root->data);

        // Reccursive Calls on Right Tree--
        inorderTraversal(root->right, order);

        return;
    }

public:
    vector<int> findInorderTraversal(Node *root)
    {
        vector<int> order;
        inorderTraversal(root, order);
        return order;
    }
};
