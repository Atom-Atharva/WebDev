// https://leetcode.com/problems/binary-tree-inorder-traversal/

// Given the root of a binary tree, return the inorder traversal of its nodes' values.

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
#include <vector>

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            vector<int> ans;
            return ans;
        }
        vector<int> tree;

        vector<int> l_tree = inorderTraversal(root->left);
        for (int i = 0; i < l_tree.size(); i++)
        {
            tree.push_back(l_tree[i]);
        }

        tree.push_back(root->val);

        vector<int> r_tree = inorderTraversal(root->right);
        for (int i = 0; i < r_tree.size(); i++)
        {
            tree.push_back(r_tree[i]);
        }

        return tree;
    }
};