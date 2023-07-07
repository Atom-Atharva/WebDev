// https://leetcode.com/problems/symmetric-tree/

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

#include <iostream>
using namespace std;
#include <vector>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool helper(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        else if (p == NULL || q == NULL)
        {
            return false;
        }

        if (p->val != q->val)
        {
            return false;
        }

        return helper(p->right, q->left) && helper(p->left, q->right);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        return helper(root->left, root->right);
    }
};