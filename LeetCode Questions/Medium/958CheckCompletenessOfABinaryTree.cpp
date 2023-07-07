// https://leetcode.com/problems/check-completeness-of-a-binary-tree/

// Given the root of a binary tree, determine if it is a complete binary tree.

// In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>
using namespace std;
#include <queue>

class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        queue<TreeNode *> nodes;
        nodes.push(root);

        bool flag = true;

        while (!nodes.empty())
        {
            TreeNode *node = nodes.front();
            nodes.pop();

            if (node == NULL)
            {
                flag = false;
                continue;
            }
            if (!flag)
            {
                return false;
            }

            nodes.push(node->left);
            nodes.push(node->right);
        }
        return true;
    }
};