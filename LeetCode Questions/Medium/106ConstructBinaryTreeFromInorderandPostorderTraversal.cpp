// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

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

class Solution
{
    TreeNode *buildTree(vector<int> &inorder, int ist, int ien, vector<int> &postorder, int pind)
    {
        // Base Case--
        if (ist > ien)
        {
            return NULL;
        }

        int element = postorder[pind];
        TreeNode *root = new TreeNode(element);

        // Search in inorder list--
        int ind;
        for (int i = ist; i <= ien; i++)
        {
            if (element == inorder[i])
            {
                ind = i;
                break;
            }
        }

        // Reccursive Call--
        TreeNode *rtree = buildTree(inorder, ind + 1, ien, postorder, pind - 1);
        TreeNode *ltree = buildTree(inorder, ist, ind - 1, postorder, pind - (ien - ind) - 1);

        // Connect subtree with Root--
        root->left = ltree;
        root->right = rtree;

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1);
    }
};