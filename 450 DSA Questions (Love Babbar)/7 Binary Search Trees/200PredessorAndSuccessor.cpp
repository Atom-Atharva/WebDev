// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

// There is BST given with the root node with the key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

// Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor.

#include <iostream>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    void findClosest(Node *root, Node *&pre, Node *&suc)
    {
        // Base Case--
        if (root == NULL)
        {
            return;
        }

        // Find Nearest Pre--
        Node *temp = root->left;
        while (temp != NULL && temp->right != NULL)
        {
            temp = temp->right;
        }

        pre = (temp != NULL) ? temp : pre;

        // Find Nearest Suc--
        temp = root->right;
        while (temp != NULL && temp->left != NULL)
        {
            temp = temp->left;
        }

        suc = (temp != NULL) ? temp : suc;

        return;
    }

public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        // Base Case--
        if (root == NULL)
        {
            return;
        }
        if (root->key == key)
        {
            // Find Neighbours--
            findClosest(root, pre, suc);
            return;
        }

        // Reccursive Call--
        if (key > root->key)
        {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
        else
        {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        }

        return;
    }
};