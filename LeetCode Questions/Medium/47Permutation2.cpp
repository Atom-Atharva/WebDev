// https://leetcode.com/problems/permutations-ii/

// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
    void permuteUnique(vector<int> &nums, vector<vector<int>> &ans, vector<int> per)
    {
        if (nums.size() == 0)
        {
            ans.push_back(per);
            return;
        }

        // Reccursion over each Element--
        for (int i = 0; i < nums.size(); i++)
        {
            // Remove Duplicate Element--
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

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
            permuteUnique(arr, ans, per);

            // Removing element from the per--
            per.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        permuteUnique(nums, ans, {});
        return ans;
    }
};