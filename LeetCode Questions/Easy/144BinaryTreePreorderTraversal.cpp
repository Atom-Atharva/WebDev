// https://leetcode.com/problems/binary-tree-preorder-traversal/

// Given the root of a binary tree, return the preorder traversal of its nodes' values.

#include <iostream>
using namespace std;
#include <vector>

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

#include <stack>

// Alternate and Optimized Solution could be Reccursive Approach as done in Ques-145(BinaryTreePostOrderTraversal).

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        stack<TreeNode *> pending_nodes;
        pending_nodes.push(root);
        while (!pending_nodes.empty())
        {
            TreeNode *node = pending_nodes.top();
            pending_nodes.pop();
            ans.push_back(node->val);

            if (node->right != NULL)
            {
                pending_nodes.push(node->right);
            }
            if (node->left != NULL)
            {
                pending_nodes.push(node->left);
            }
        }
        return ans;
    }
};