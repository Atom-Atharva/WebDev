// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

// Given an integer array nums where the elements are sorted in ascending order, convert it to a
// height-balanced
//  binary search tree.

//  Definition for a binary tree node.
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
#include <vector>

class Solution
{
public:
    TreeNode *helper(vector<int> &nums, int st, int en)
    {
        if (st > en)
        {
            return NULL;
        }

        int mid = (st + en) / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        TreeNode *ltree = helper(nums, st, mid - 1);
        TreeNode *rtree = helper(nums, mid + 1, en);

        root->left = ltree;
        root->right = rtree;

        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
};