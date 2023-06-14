/*
https://www.techiedelight.com/?problem=PreorderTreeTraversal

Given the root of a binary tree, return the preorder traversal of its nodes' values.

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

Output: [1, 2, 4, 3, 5, 7, 8, 6]

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

    void preorderTraversal(Node *root, vector<int> &order)
    {
        // Base Case--
        if (root == NULL)
        {
            return;
        }

        // Store Parent--
        order.push_back(root->data);

        // Reccursiver Call on Subtrees--
        preorderTraversal(root->left, order);
        preorderTraversal(root->right, order);

        return;
    }

public:
    vector<int> findPreorderTraversal(Node *root)
    {
        vector<int> order;
        preorderTraversal(root, order);
        return order;
    }
};
