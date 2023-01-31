// https://leetcode.com/problems/single-number/

// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> maps;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maps.count(nums[i]) > 0)
            {
                maps[nums[i]]++;
                continue;
            }
            maps[nums[i]] = 1;
        }

        int ans = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maps[nums[i]] == 1)
            {
                ans = nums[i];
                return ans;
            }
        }
        return -1;
    }
};