// https://leetcode.com/problems/delete-node-in-a-bst/

// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.

/*****************MOST IMPORTANT QUESTION************************/

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
    int minValue(TreeNode *root)
    {
        if (root->left == NULL)
        {
            return root->val;
        }

        int ans = minValue(root->left);
        return ans;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // Base Case--
        if (root == NULL)
        {
            return root;
        }

        // Go to key--
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // Leaf Node & Right Node Only Present--
            if (root->left == NULL)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }

            // Left Node Only Present--
            else if (root->right == NULL)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            // Replace minValue to delete node and now delete minValued node--
            else
            {
                root->val = minValue(root->right);
                root->right = deleteNode(root->right, root->val);
            }
        }

        return root;
    }
};

// class Solution
// {
//     TreeNode *searchNode(TreeNode *root, int key)
//     {
//         // Base Case--
//         if (root == NULL)
//         {
//             return NULL;
//         }
//         if ((root->left != NULL && root->left->val == key) || (root->right != NULL && root->right->val == key))
//         {
//             return root;
//         }
//         if (root->val == key)
//         {
//             return root;
//         }

//         // Reccursive Calls--
//         return (key > root->val) ? searchNode(root->right, key) : searchNode(root->left, key);
//     }

// public:
//     TreeNode *deleteNode(TreeNode *root, int key)
//     {
//         // Search Node's Parent--
//         TreeNode *node = searchNode(root, key);
//         if (node == NULL)
//         {
//             return root;
//         }

//         // Deletion of Node--
//         bool l = 0, t = 0;
//         TreeNode *val;
//         if (node->val == key)
//         {
//             val = node;
//             t = 1;
//         }
//         else if (node->left->val == key)
//         {
//             val = node->left;
//             l = 1;
//         }
//         else
//         {
//             val = node->right;
//             l = 0;
//         }

//         // Storing for future--
//         TreeNode *left = val->left;
//         TreeNode *right = val->right;

//         delete val;

//         // Rearrange All right Node to end of the lefts bottom right--
//         if (!t)
//         {
//             if (l)
//             {
//                 node->left = left;
//             }
//             else
//             {
//                 node->right = left;
//             }
//         }
//         else
//         {
//             root = left;
//         }

//         // Go to left's rightest--
//         TreeNode *down = left;
//         while (down->right != NULL)
//         {
//             down = down->right;
//         }

//         down->right = right;

//         return root;
//     }
// };