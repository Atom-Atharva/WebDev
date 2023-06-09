// https://www.codingninjas.com/codestudio/problems/find-a-value-in-bst_1170063

// Finding a Value in BST--

#include <iostream>
using namespace std;

// Following is the TreeNode class structure
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    bool findNode(TreeNode<int> *root, int key)
    {
        // Base Case--
        if (root == NULL)
        {
            return false;
        }
        if (key == root->data)
        {
            return true;
        }

        // Reccursive Call-
        bool ans = (key > root->data) ? findNode(root->right, key) : findNode(root->left, key);

        return ans;
    }
};