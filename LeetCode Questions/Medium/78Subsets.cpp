// https://leetcode.com/problems/subsets/

// Given an integer array nums of unique elements, return all possible
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void combinations(vector<int> &nums, vector<vector<int>> &ans, vector<int> &comb, int i)
    {
        // Base Case--
        if (i == nums.size())
        {
            return;
        }

        // Itterate Over each letter--
        for (; i < nums.size(); i++)
        {
            // Adding letter to comb--
            comb.push_back(nums[i]);
            ans.push_back(comb);

            // Reccusion on Combination--
            combinations(nums, ans, comb, i + 1);

            // Remove letter from comb--
            comb.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        ans.push_back({});
        vector<int> comb;
        combinations(nums, ans, comb, 0);
        return ans;
    }
};