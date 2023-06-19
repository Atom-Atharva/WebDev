// https://www.codingninjas.com/studio/problems/bst-from-preorder_2689307

#include <iostream>
using namespace std;
#include <vector>

// Following is the Binary Tree node structure
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
    ~TreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    // Base Case--
    if (preOrder.size() == 0)
    {
        return NULL;
    }

    // Creating root node--
    TreeNode<int> *root = new TreeNode<int>(preOrder[0]);

    // Finding Breakpoint--
    int bp = 1;
    for (int i = 1; i < preOrder.size(); i++, bp++)
    {
        if (preOrder[i] > preOrder[0])
        {
            break;
        }
    }

    // Creating new arrays--
    vector<int> leftOrder;
    for (int i = 1; i < bp; i++)
    {
        leftOrder.push_back(preOrder[i]);
    }

    vector<int> rightOrder;
    for (int i = bp; i < preOrder.size(); i++)
    {
        rightOrder.push_back(preOrder[i]);
    }

    // Call Reccursive Functions--
    TreeNode<int> *left = preOrderTree(leftOrder);
    TreeNode<int> *right = preOrderTree(rightOrder);

    // Establish Connections--
    root->left = left;
    root->right = right;

    return root;
}