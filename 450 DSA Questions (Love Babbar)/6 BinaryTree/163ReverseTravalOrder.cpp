// https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

// Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.

// Example 1:

// Input :
//         1
//       /   \
//      3     2

// Output: 3 2 1
// Explanation:
// Traversing level 1 : 3 2
// Traversing level 0 : 1

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
    void reverse(vector<int> &arr)
    {
        for (int i = 0; i < arr.size() / 2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[arr.size() - i - 1];
            arr[arr.size() - i - 1] = temp;
        }

        return;
    }

public:
    // Function to return the level order traversal of a tree.
    vector<int> reverseLevelOrder(Node *root)
    {
        if (root == NULL)
        {
            return {};
        }

        queue<Node *> level;
        level.push(root);
        vector<int> ans;

        while (!level.empty())
        {
            Node *temp = level.front();
            ans.push_back(temp->data);
            level.pop();
            if (temp->right != NULL)
            {
                level.push(temp->right);
            }
            if (temp->left != NULL)
            {
                level.push(temp->left);
            }
        }

        reverse(ans);

        return ans;
    }
};