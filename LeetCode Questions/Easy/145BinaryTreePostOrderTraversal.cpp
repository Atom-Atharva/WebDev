// https://leetcode.com/problems/binary-tree-postorder-traversal/

// Given the root of a binary tree, return the postorder traversal of its nodes' values.

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

class Solution
{
    void postOrderTraversal(TreeNode *root, vector<int> *ans)
    {
        if (root == NULL)
        {
            return;
        }
        postOrderTraversal(root->left, ans);
        postOrderTraversal(root->right, ans);
        ans->push_back(root->val);
        return;
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postOrderTraversal(root, &ans);
        return ans;
    }
};