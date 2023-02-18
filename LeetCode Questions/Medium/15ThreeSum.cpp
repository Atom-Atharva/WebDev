// https://leetcode.com/problems/3sum/

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // Sorting nums array--
        sort(nums.begin(), nums.end());

        // Base Cases--
        if (nums.size() < 3)
        {
            return {};
        }
        if (nums[0] > 0)
        {
            return {};
        }

        // Creating Hashmap with indices--
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++)
        {
            hashMap[nums[i]] = i;
        }

        // Finding distinct trios
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                int req = -(nums[i] + nums[j]);
                if (hashMap.count(req) > 0 && hashMap.find(req)->second > j)
                {
                    ans.push_back({nums[i], nums[j], req});
                }

                //Updating j to last occurance of the element--
                j = hashMap.find(nums[j])->second;
            }

            //Updation i to last occurance of the element--
            i = hashMap.find(nums[i])->second;
        }
        return ans;
    }
};