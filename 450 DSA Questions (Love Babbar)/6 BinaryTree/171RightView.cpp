// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

// Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

// Right view of following tree is 1 3 7 8.

//           1
//        /     \
//      2        3
//    /   \      /    \
//   4     5   6    7
//     \
//      8

#include <iostream>
using namespace std;
#include <vector>

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

// Should return  right view of tree
class Solution
{
    void travel(Node *root, int level, vector<int> &view)
    {
        // Base Case--
        if (root == NULL)
        {
            return;
        }

        // First Element of each Level--
        if (view.size() == level)
        {
            view.push_back(root->data);
        }

        // Reccursive Calls--
        travel(root->right, level + 1, view);
        travel(root->left, level + 1, view);

        return;
    }

public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> view;
        travel(root, 0, view);
        return view;
    }
};