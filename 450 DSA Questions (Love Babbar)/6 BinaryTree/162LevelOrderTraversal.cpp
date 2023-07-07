// https://practice.geeksforgeeks.org/problems/level-order-traversal/1

// Given a binary tree, find its level order traversal.
// Level order traversal of a tree is breadth-first traversal for the tree.

// Example 1:

// Input:
//     1
//   /   \ 
//  3     2
// Output:1 3 2

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

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
    // Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node *node)
    {
        if (node == NULL)
        {
            return {};
        }

        queue<Node *> level;
        level.push(node);
        vector<int> ans;

        while (!level.empty())
        {
            Node *temp = level.front();
            ans.push_back(temp->data);
            level.pop();
            if (temp->left != NULL)
            {
                level.push(temp->left);
            }
            if (temp->right != NULL)
            {
                level.push(temp->right);
            }
        }

        return ans;
    }
};