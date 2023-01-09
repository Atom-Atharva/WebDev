// https://leetcode.com/problems/path-sum/

// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

// A leaf is a node with no children.

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

class Solution
{
public:
    bool helper(TreeNode *root, int targetSum, int sum)
    {
        if (root == NULL)
        {
            return false;
        }
        if (sum + root->val == targetSum && root->left == NULL && root->right == NULL)
        {
            return true;
        }
    
        bool ltree = helper(root->left, targetSum, sum + root->val);
        bool rtree = helper(root->right, targetSum, sum + root->val);

        if (ltree || rtree)
        {
            return true;
        }
        return false;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return helper(root, targetSum, 0);
    }
};