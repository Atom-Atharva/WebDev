// https://leetcode.com/problems/sum-root-to-leaf-numbers/

// You are given the root of a binary tree containing digits from 0 to 9 only.

// Each root-to-leaf path in the tree represents a number.

// For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
// Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

// A leaf node is a node with no children.

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
    void sumNumbers(TreeNode *root, int &sum, int num)
    {
        // Base Case--
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            num = num * 10 + root->val;
            sum += num;
            return;
        }

        // Small Calculation--
        num = num * 10 + root->val;

        // Reccursive Call--
        sumNumbers(root->left, sum, num);
        sumNumbers(root->right, sum, num);

        return;
    }

public:
    int sumNumbers(TreeNode *root)
    {
        int ans = 0;
        sumNumbers(root, ans, 0);
        return ans;
    }
};