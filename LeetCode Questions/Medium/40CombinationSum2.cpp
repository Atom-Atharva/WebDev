// https://leetcode.com/problems/combination-sum-ii/

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{

    void sum(vector<int> &candidates, int target, vector<int> &arr, vector<vector<int>> &ans, int i)
    {
        // Base Case--
        if (target == 0)
        {
            ans.push_back(arr);
            return;
        }
        if (target < 0 || i == candidates.size())
        {
            return;
        }

        // Case-1 : Taking candidate[i]
        arr.push_back(candidates[i]);
        sum(candidates, target - candidates[i], arr, ans, i + 1);
        arr.pop_back();

        // Case-2 : Not Taking and candidate[i]
        int j = i + 1;
        while (j < candidates.size())
        {
            if (candidates[j] != candidates[j - 1])
            {
                break;
            }
            j++;
        }
        sum(candidates, target, arr, ans, j);

        return;
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<int> arr;
        vector<vector<int>> ans;

        sum(candidates, target, arr, ans, 0);

        return ans;
    }
};