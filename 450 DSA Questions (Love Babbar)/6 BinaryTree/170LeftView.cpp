// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

// Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

// Left view of following tree is 1 2 4 8.

//           1
//        /     \
//      2        3
//    /     \    /    \
//   4     5   6    7
//    \
//      8

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

//  A binary tree node
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
        travel(root->left, level + 1, view);
        travel(root->right, level + 1, view);

        return;
    }

public:
    // Function to return a list containing elements of left view of the binary tree.
    vector<int> leftView(Node *root)
    {
        vector<int> view;
        travel(root, 0, view);
        return view;
    }
};