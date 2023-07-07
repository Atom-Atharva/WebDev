// https://leetcode.com/problems/4sum/

// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // Base Case--
        if (nums.size() < 4)
        {
            return {};
        }

        // Sorting Array--
        sort(nums.begin(), nums.end());

        // Creating a HashMap--
        unordered_map<int, int> val;
        for (int i = 0; i < nums.size(); i++)
        {
            //<int(val),int(add)>
            // Last Occurance Saved.
            val[nums[i]] = i;
        }

        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 3; i++)
        {
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                for (int k = j + 1; k < nums.size() - 1; k++)
                {
                    long sum = (long)nums[i] + nums[j] + nums[k];
                    long rem = (long)target - sum;
                    if (sum > INT_MAX || sum < INT_MIN)
                    {
                        continue;
                    }

                    if (val.count(rem) > 0 && val.find(rem)->second > k)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], (int)rem});
                    }

                    // Removing Dublicacy--
                    // 111222333
                    k = val.find(nums[k])->second;
                }
                j = val.find(nums[j])->second;
            }
            i = val.find(nums[i])->second;
        }
        return ans;
    }
};