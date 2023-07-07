// https://leetcode.com/problems/permutations/

// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void permute(vector<int> &nums, vector<vector<int>> &ans, vector<int> per)
    {
        if (nums.size() == 0)
        {
            ans.push_back(per);
            return;
        }

        // Reccursion over each Element--
        for (int i = 0; i < nums.size(); i++)
        {
            // Creating new array--
            vector<int> arr;
            for (int j = 0; j < nums.size(); j++)
            {
                if (j == i)
                {
                    continue;
                }
                arr.push_back(nums[j]);
            }

            // Adding element in the per--
            per.push_back(nums[i]);

            // Passing new array in reccursion--
            permute(arr, ans, per);

            // Removing element from the per--
            per.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        permute(nums, ans, {});
        return ans;
    }
};