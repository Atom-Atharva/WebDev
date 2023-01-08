// https://leetcode.com/problems/balanced-binary-tree/

// Given a binary tree, determine if it is
// height-balanced.

#include <iostream>
using namespace std;

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

class Solution
{
public:
    // Optimized Solution--
    int check(TreeNode *root, bool &ans)
    {
        if (root == NULL)
        {
            return 0;
        }

        if (!ans)
        {
            return 0;
        }

        int lh = check(root->left, ans);
        int rh = check(root->right, ans);

        if (abs(lh - rh) > 1)
        {
            ans = false;
        }
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode *root)
    {
        bool ans = true;
        int temp = check(root, ans);

        return ans;
    }

    // Naive Solution--
    //  int height(TreeNode *root)
    //  {
    //      if (root == NULL)
    //      {
    //          return 0;
    //      }

    //     int lh = height(root->left);
    //     int rh = height(root->right);

    //     return max(rh, lh) + 1;
    // }

    // bool isBalanced(TreeNode *root)
    // {
    //     if (root == NULL)
    //     {
    //         return true;
    //     }

    //     int lh = height(root->left);
    //     int rh = height(root->right);

    //     if (abs(lh - rh) <= 1 && isBalanced(root->right) && isBalanced(root->left))
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }
};
