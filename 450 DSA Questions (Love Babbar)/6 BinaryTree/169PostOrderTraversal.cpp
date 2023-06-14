/*
https://www.techiedelight.com/?problem=PostorderTreeTraversal

Given the root of a binary tree, return the postorder traversal of its nodes' values.

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

Output: [4, 2, 7, 8, 5, 6, 3, 1]

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
    void postOrderTraversal(Node *root, vector<int> &order)
    {
        // Base Case--
        if (root == NULL)
        {
            return;
        }

        // Reccursive Calls on Subtrees--
        postOrderTraversal(root->left, order);
        postOrderTraversal(root->right, order);

        // Insert Parent in vector--
        order.push_back(root->data);

        return;
    }

public:
    vector<int> findPostorderTraversal(Node *root)
    {
        vector<int> order;
        postOrderTraversal(root, order);
        return order;
    }
};
