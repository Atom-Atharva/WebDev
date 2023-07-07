// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

// The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes)
// Example 1:

// Input:
//        1
//      /  \
//     2    3
// Output: 3

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    // Pair of Diameter and MaxNodes--
    pair<int, int> diameterHelper(Node *root)
    {
        // Base Case--
        if (root == NULL)
        {
            return {0, 0};
        }

        // Reccursion--
        pair<int, int> ltree = diameterHelper(root->left);
        pair<int, int> rtree = diameterHelper(root->right);

        // Calculate Curr Diameter--
        int dia = ltree.second + rtree.second + 1;
        int maxnodes = max(ltree.second, rtree.second) + 1;
        int maxdia = max(dia, max(ltree.first, rtree.first));

        return {maxdia, maxnodes};
    }

public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        return diameterHelper(root).first;
    }
};