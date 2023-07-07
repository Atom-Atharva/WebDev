// https://leetcode.com/problems/combination-sum/

// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
// frequency
//  of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
    // Helper Function--
    void combinationSum(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &arr, int i)
    {
        // Base Case--
        if (target == 0)
        {
            ans.push_back(arr);
            return;
        }

        // Reccursive Calls--
        while (i < candidates.size() && target - candidates[i] >= 0)
        {
            // Push number in array--
            arr.push_back(candidates[i]);

            // Reccursive Call--
            combinationSum(candidates, target - candidates[i], ans, arr, i);
            i++;

            // Backtracking--
            arr.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<int> arr;
        vector<vector<int>> ans;

        combinationSum(candidates, target, ans, arr, 0);
        return ans;
    }
};